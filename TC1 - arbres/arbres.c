#include <stdlib.h>
#include <stdio.h>
#include "arbres.h"

int nodeCount = 0;
int nodeCurID = 0;

// création d'un nouveau noeud d'arbre binaire
int newBinaryTreeElement(BinaryTreeElement** node) {
	*node = (BinaryTreeElement*)malloc(sizeof(BinaryTreeElement));
	if (node == NULL) {
		return EXIT_FAILURE;
	}
	(*node)->leftChild = NULL;
	(*node)->rightChild = NULL;
	(*node)->nodeID = nodeCurID;
	nodeCurID++;

	return EXIT_SUCCESS;
}

int newTree(BinaryTree** tree) {
	if (tree != NULL) {
		BinaryTreeElement *tmp;
		newBinaryTreeElement(&tmp);
		if (tmp != NULL) {
			*tree = (BinaryTree*)malloc(sizeof(BinaryTree));
			if (*tree != NULL) {
				(*tree)->nodeCount = 0;
				(*tree)->anchor = tmp;
				(*tree)->anchor->data = 0xFFFF;
				(*tree)->anchor->nodeID = 0;
				return EXIT_SUCCESS;
			}
		}
	}
	return EXIT_FAILURE;
}


// renvoie un curseur sur le noeud à la racine de l'arbre
Cursor getCursorOnRoot(BinaryTree tree) {
	Cursor tmp;
	tmp.pointeur = tree.anchor;
	tmp.side = Left;
	return(tmp);
}

// renvoie un pointeur sur le noeud désigné par le curseur
BinaryTreeElement* getNode(Cursor curs) {
	BinaryTreeElement* tmp;
	tmp = NULL;
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	return tmp;
}

// greffe d'un fils droit ou gauche sur le noeud désigné par le curseur 
void graftChildNode(Cursor father, BinaryTreeElement* node, Direction side) {
	if (father.side == Left) {
		father.pointeur->leftChild == node;
	}
	if (father.side == Right) {
		father.pointeur->rightChild == node;
	}
}

Cursor getLeftChild(Cursor curs) {
	Cursor tmp = curs;
	goDown(&tmp, Left);
	return tmp;
}

Cursor getRightChild(Cursor curs) {
	Cursor tmp = curs;
	goDown(&tmp, Right);
	return tmp;
}

// faire descendre un curseur dans l'arbre, à droite ou à gauche
void goDown(Cursor* curs, Direction dir) {
	if (curs->side == Left) {
		curs->pointeur = curs->pointeur->leftChild;
	}
	if (curs->side == Right) {
		curs->pointeur = curs->pointeur->rightChild;
	}
	curs->side = dir;
}

// indique qu'il n'y a pas de fils dans la direction du curseur
// le curseur ne désigne pas un noeud
// on pourrait donc greffer (cf insertValueInAbrAt) un nouveau noeud 
bool isAtTheEnd(Cursor curs) {
	if (curs.side == Left) {
		if (curs.pointeur->leftChild == NULL) {
			return true;
		}
	}
	else {
		if (curs.pointeur->rightChild == NULL) {
			return true;
		}
	}
	return false;
}

// verifie que le noeud désigné par le cursor n'a pas de fils, et est donc une feuille
bool isALeaf(Cursor curs) {
	BinaryTreeElement* tmp;
	newBinaryTreeElement(&tmp);
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	if (tmp != NULL && tmp->leftChild == NULL && tmp->rightChild == NULL) {
		return true;
	}
	return false;
}

// vérifie que le noeud désigné par le cursor possède un successeur dans la direction indiquée
bool hasAChild(Cursor curs, Direction D) {
	BinaryTreeElement* tmp;
	newBinaryTreeElement(&tmp);
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	if (D == Left) {
		if (tmp != NULL && tmp->leftChild != NULL) {
			return true;
		}
	}
	if (D == Right) {
		if (tmp != NULL && tmp->rightChild != NULL) {
			return true;
		}
	}
	return false;
}

// renvoie la valeur stockée dans le champ data d'un noeud
int getValue(Cursor curs) {
	BinaryTreeElement* tmp;
	newBinaryTreeElement(&tmp);
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	if (tmp != NULL) {
		return tmp->data;
	}
	return EXIT_FAILURE;
}

// change la valeur contenue dans le champ data d'un noeud
void modifyValue(Cursor curs, int X) {
	BinaryTreeElement* tmp;
	newBinaryTreeElement(&tmp);
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	if (tmp != NULL) {
		tmp->data = X;
	}
}

int freeBinaryTreeElement(BinaryTreeElement** node) {
	free(*node);
	nodeCount--;
	return 0;
}

// supprime un noeud d'une branche 
// pour les cas suivants
// cas 1 :   O     O       cas 2 :   O       O
//          /       \               /         \
//    a:   X   ou b: X          a: X     ou b: X
//        /         /               \           \
//       O         O                 O           O
//
//  le noeud X à supprimer         le noeud X à supprimer
//  a un fils gauche               a un fils droit
//
// cela donne
//         O      O             O          O
//  1-a:  /  1-b:  \    2-a:   /    2-b :   \
//       O          O         O              O
void removeNode(Cursor curs) {
	BinaryTreeElement* tmp;
	newBinaryTreeElement(&tmp);
	if (curs.side == Left) {
		tmp = curs.pointeur->leftChild;
	}
	if (curs.side == Right) {
		tmp = curs.pointeur->rightChild;
	}
	if (tmp == NULL) {
		return EXIT_FAILURE;
	}
	if (tmp->leftChild != NULL) {
		if (curs.side == Left) {
			curs.pointeur = tmp->leftChild;
			curs.pointeur->rightChild = tmp->rightChild;
		}
		else if (curs.side == Right) {
			curs.pointeur = tmp->leftChild;
			curs.pointeur->rightChild = tmp->rightChild;
		}
	}
	else if (tmp->rightChild != NULL) {
		curs.pointeur = tmp->rightChild;
	}
	freeBinaryTreeElement(&tmp);
}

// insere une nouvelle valeur dans une nouvelle feuille à la position indiquée par le curseur
// qui doit être en fin (cf estEnFin())
// utilisé par la fonction addValueToABR() pour ajouter une nouvelle valeur dans l'arbre
void insertValueInAbrAt(Cursor curs, int X) {
	if (estEnFin(curs.pointeur))
}