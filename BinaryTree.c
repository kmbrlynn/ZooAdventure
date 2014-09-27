#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BinaryTree.h"

bool hasLeft(BinaryNode* node)
{
	if (node-> left != NULL)
		return true;
	else
		return false;
}

bool hasRight(BinaryNode* node)
{
	if (node-> right != NULL)
		return true;
	else
		return false;
}

BinaryNode* makeNode(NodeData data)
{
	BinaryNode* node = (BinaryNode*)malloc(sizeof(BinaryNode));

	strcpy(node-> data, data);
	node-> left = NULL;
	node-> right = NULL;
	return node;
}

bool isLeaf(BinaryNode* node)
{
	if((!hasLeft(node)) && (!hasRight(node)))
		return true;
	else
		return false;
}

BinaryTree* initBinaryTree(void)
{
	BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));

	tree-> root = NULL;
	return tree;
}

bool isEmpty(BinaryTree* tree)
{
	if(tree-> root != NULL)
		return false;
	else
		return true;
}

BinaryNode* addRoot(BinaryTree* tree, NodeData data)
{
	BinaryNode* newNode = NULL;

	if(isEmpty(tree))
	{
		tree-> root = makeNode(data);
		newNode = tree-> root;
	}
	else
	{
		fprintf(stderr, "Tree already has a root.\n");
		newNode = NULL;
	}
	return newNode;
}

BinaryNode* addChild(BinaryNode* parent, int leftOrRight, NodeData data)
{
	BinaryNode* newNode = NULL;

	if(parent != NULL)
	{
		if(leftOrRight == passLeftChild)
		{
			parent-> left = makeNode(data);
			newNode = parent-> left;
		}
		else if(leftOrRight == passRightChild)
		{
			parent-> right = makeNode(data);
			newNode = parent-> right;
		}
	}
	else
	{
		fprintf(stderr, "Cannot add child to a null parent.\n");
		newNode = NULL;
	}
	return newNode;
}

void emptySubtree(BinaryNode* node)
{
	if(node == NULL)
		;
	else if(isLeaf(node))
		free(node);
	else
	{
		emptySubtree(node-> left);
		emptySubtree(node-> right);
		free(node);
	}
	return;
}

void destroyTree(BinaryTree* tree)
{
	if(!isEmpty(tree))
	{
		emptySubtree(tree-> root);
	}
	else
		free(tree);
	return;
}

int numNodesSubtree(BinaryNode* node)
{
	int n, nLeft, nRight;

	if(node == NULL)
		n = 0;
	else if(isLeaf(node))
		n = 1;
	else
	{
		nLeft = numNodesSubtree(node-> left);
		nRight = numNodesSubtree(node-> right);
		n = nLeft + nRight + 1;
	}
	return n;
}

int numLeavesSubtree(BinaryNode* node)
{
	int n, nLeft, nRight;

	if(node == NULL)
		n = 0;
	else if(isLeaf(node))
		n = 1;
	else
	{
		nLeft = numLeavesSubtree(node-> left);
		nRight = numLeavesSubtree(node-> right);
		n = nLeft + nRight;
	}
	return n;
}

int heightSubtree(BinaryNode* node)
{
	int h, hLeft, hRight;

	if(node == NULL)
		h = 0;
	else if(isLeaf(node))
		h = 1;
	else
	{
		hLeft = numLeavesSubtree(node-> left);
		hRight = numLeavesSubtree(node-> right);
		if (hLeft >= hRight)
			h = hLeft;
		else if(hLeft < hRight)
			h = hRight;
	}
	return h;
}



























































