#define passLeftChild 0
#define passRightChild 1
#define DATA_FIELD 75

typedef char NodeData[DATA_FIELD];

typedef struct binaryNode 
{
	NodeData data;
	struct binaryNode* left;
	struct binaryNode* right;
} BinaryNode;

typedef struct binaryTree
{
	BinaryNode* root;
} BinaryTree;

//Postcondition: Returns [true] if the node has a left child
//				 Returns [false] if there is no left child
bool hasLeft(BinaryNode* node);

//Postcondition: Returns [true] if the node has a right child
//				 Returns [false] if there is no right child
bool hasRight(BinaryNode* node);

//Postcondition: An empty node is created
//				 Returns a pointer to that node
BinaryNode* makeNode(NodeData data);

//Postcondition: Returns [true] if the node is a leaf
//				 Returns [false] if the node is not a leaf
bool isLeaf(BinaryNode* node);

//Postcondition: An empty binary tree is created
//				 Returns a pointer to its root
BinaryTree* initBinaryTree(void);

//Postcondition: Returns [true] if the tree is empty
//				 Returns [false] if the tree is not empty
bool isEmpty(BinaryTree* tree);

//Postcondition: A root is added to an empty tree
//				 Returns a poitner to that root
BinaryNode* addRoot(BinaryTree* tree, NodeData data);

//Postcondition: A child is added to a parent node
//				 Returns a poitner to the child
BinaryNode* addChild(BinaryNode* parent, int leftOrRight, NodeData data);

//Postcondition: The tree is recursively emptied
//				 Uses post-Order traversal
//				 Returns nothing
void emptySubtree(BinaryNode* node);

//Poscondition: The binary tree is destroyed.
//				Returns nothing
void destroyTree(BinaryTree* tree);

//Postcondition: Returns the number of nodes in a tree
//				 Uses post-order traversal
int numNodesSubtree(BinaryNode* node);

//Postcondition: Returns the number of leaves in a tree
//				 Uses post-order traversal
int numLeavesSubtree(BinaryNode* node);

//Postcondition: Returns the height of a tree
//				 Uses post-order traversal
int heightSubtree(BinaryNode* node);