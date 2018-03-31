#ifndef tree_node_h
#define tree_node_h

#define TYPE char

struct TreeNode {
	TYPE element;
	TreeNode *leftChild;
	TreeNode *rightChild;
};

#endif
