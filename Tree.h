#ifndef tree_h
#define tree_h

#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;

template <class T>
class Tree {
	public:
		Tree(TreeNode<T> *r=NULL):root(r){}
		Tree(int node_num);
		~Tree();

		void addNodeL(int i, int j);
		void addNodeR(int i, int j);
		void setElement(int i, char theElement);
		bool empty() const {
			return theSize==0;
		}
		int size() const {
			return theSize;
		}
		void preOrder();
		void inOrder();
		void postOrder();
		void levelOrder();
	private:
		TreeNode<T> *root;
		int theSize;
		void preOrder(TreeNode<T> *parent);
		void inOrder(TreeNode<T> *parent);
		void postOrder(TreeNode<T> *parent);
		void levelOrder(TreeNode<T> *parent);
};

template <class T>
void Tree<T>::preOrder() {
	cout<<"前序遍历：";
	preOrder(root);
	cout<<endl;
}

template <class T>
void Tree<T>::preOrder(TreeNode<T> *parent) {
	if (parent != NULL) {
		cout<<parent->element<<" ";
		preOrder(parent->leftChild);
		preOrder(parent->rightChild);
	}
}

template <class T>
void Tree<T>::inOrder() {
    cout<<"中序遍历：";
    inOrder(root);
    cout<<endl;
}

template <class T>
void Tree<T>::inOrder(TreeNode<T> *parent) {
    if (parent != NULL) {
        inOrder(parent->leftChild);
        cout<<parent->element<<" ";
        inOrder(parent->rightChild);
    }
}

template <class T>
void Tree<T>::postOrder() {
    cout<<"后序遍历：";
    postOrder(root);
    cout<<endl;
}

template <class T>
void Tree<T>::postOrder(TreeNode<T> *parent) {
    if (parent != NULL) {
        postOrder(parent->leftChild);
        postOrder(parent->rightChild);
        cout<<parent->element<<" ";
    }
}

template <class T>
void Tree<T>::levelOrder() {
	cout<<"层次遍历：";
	levelOrder(root);
	cout<<endl;
}

template <class T>
void Tree<T>::levelOrder(TreeNode<T> *parent) {
	list<TreeNode<T> *> list;
	while (parent != NULL) {
		cout<<parent->element<<" ";
		if (parent->leftChild != NULL) list.push_back(parent->leftChild);
		if (parent->rightChild != NULL) list.push_back(parent->rightChild);

		if (list.empty()) return;

		parent=list.front();
		list.pop_front();
	}
}

template <class T>
Tree<T>::Tree(int node_num) {
	root=new TreeNode<T>[node_num];
	theSize=node_num;
}

template <class T>
Tree<T>::~Tree() {
	if (root!=NULL) delete []root;
}

template <class T>
void Tree<T>::setElement(int i, char theElement) {
	root[i].element=theElement;
}

template <class T>
void Tree<T>::addNodeL(int i, int j) {
	TreeNode<T> *parent=&root[i];
	TreeNode<T> *child=&root[j];

	parent->leftChild=child;
}

template <class T>
void Tree<T>::addNodeR(int i, int j) {
    TreeNode<T> *parent=&root[i];
    TreeNode<T> *child=&root[j];

    parent->rightChild=child;
}

#endif
