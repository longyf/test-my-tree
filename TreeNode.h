#ifndef tree_node_h
#define tree_node_h

template <class T>

struct TreeNode {
	T element;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

#endif
