#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "BinaryTree.h"

#define MAX_NODES 15

void fillDecisionTree(BinaryTree* tree);
void play(BinaryTree* tree);

const int maxIterations = MAX_NODES / 2;

int main(int argc, char* argv[])
{
	int numNodes;
	int numLeaves;
	int treeHeight;

	BinaryTree* tree = initBinaryTree();

	fillDecisionTree(tree);

	printf("\n");
	printf("Number of nodes in the tree: %d\n", numNodesSubtree(tree-> root));
	printf("Number of leaves in the tree: %d\n",numLeavesSubtree(tree->root));
	printf("Number of levels in the tree: %d\n", heightSubtree(tree->root));
	printf("\n");

	play(tree);
	emptySubtree(tree-> root);
	destroyTree(tree);

	return 0;
}

void fillDecisionTree(BinaryTree* tree)
{	
	int i = 0;
	BinaryNode* nodeArray[MAX_NODES];
	NodeData dataArray[MAX_NODES] = {
		"\nAre you in the aquarium section of the zoo? (y/n) ",
		"Does this animal fly? (y/n) ",
		"Is this animal a mammal? (y/n) ",
		"Is this animal a marsupial? (y/n) ",
		"Is this animal extinct? (y/n) ",
		"Is this animal a cephalopod? (y/n) ",
		"Does this animal have tusks? (y/n) ",
		"\n-----> It's an elephant!\n",
		"\n-----> It's a kangaroo!\n",
		"\n-----> It's an eagle!\n",
		"\n-----> It's a pterodactyl!\n",
		"\n-----> It's a shark!\n",
		"\n-----> It's an octopus!\n",
		"\n-----> It's a dolphin!\n",
		"\n-----> It's a walrus!\n"};
	
	nodeArray[i] = addRoot(tree, dataArray[i]);

	for (i = 0; i < maxIterations; i++)
	{
		nodeArray[2*i + 1] = addChild(nodeArray[i], passLeftChild, dataArray[2*i + 1]);
		nodeArray[2*i + 2] = addChild(nodeArray[i], passRightChild, dataArray[2*i + 2]);
	}

	return;
}

void play(BinaryTree* tree)
{
	char cont = 'c';
	char answer;
	BinaryNode* currentNode;

	while (cont == 'c')
	{
		printf("=====================================================");
		printf("\n================= WELCOME TO THE ZOO ================\n");
		
		currentNode = tree-> root;
		printf("%s", currentNode-> data);
		scanf(" %c", &answer);
		
		while(currentNode != NULL)
		{
			if (answer == 'n')
			{
				currentNode = currentNode-> left;
				printf("%s", currentNode-> data);
				if(currentNode-> left == NULL)
					break;
				scanf(" %c", &answer);
			}
			else if (answer == 'y')
			{
				currentNode = currentNode-> right;
				printf("%s", currentNode-> data);
				if(currentNode-> left == NULL)
					break;
				scanf(" %c", &answer);	
			}
		}
	
		printf("\nPress 'c' to continue at the zoo, or 'q' to quit: ");
		scanf(" %c", &cont);	
	}

	return;
}
