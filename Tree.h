#ifndef tree_h
#define tree_h

#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;

class Tree {
	public:
		Tree(TreeNode *r=NULL):root(r){}
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
		TreeNode *root;
		int theSize;
		void preOrder(TreeNode *parent);
		void inOrder(TreeNode *parent);
		void postOrder(TreeNode *parent);
		void levelOrder(TreeNode *parent);
};

void Tree::preOrder() {
	cout<<"前序遍历：";
	preOrder(root);
	cout<<endl;
}

void Tree::preOrder(TreeNode *parent) {
	if (parent != NULL) {
		cout<<parent->element<<" ";
		preOrder(parent->leftChild);
		preOrder(parent->rightChild);
	}
}

void Tree::inOrder() {
    cout<<"中序遍历：";
    inOrder(root);
    cout<<endl;
}

void Tree::inOrder(TreeNode *parent) {
    if (parent != NULL) {
        inOrder(parent->leftChild);
        cout<<parent->element<<" ";
        inOrder(parent->rightChild);
    }
}

void Tree::postOrder() {
    cout<<"后序遍历：";
    postOrder(root);
    cout<<endl;
}

void Tree::postOrder(TreeNode *parent) {
    if (parent != NULL) {
        postOrder(parent->leftChild);
        postOrder(parent->rightChild);
        cout<<parent->element<<" ";
    }
}

void Tree::levelOrder() {
	cout<<"层次遍历：";
	levelOrder(root);
	cout<<endl;
}

void Tree::levelOrder(TreeNode *parent) {
	list<TreeNode *> list;
	while (parent != NULL) {
		cout<<parent->element<<" ";
		if (parent->leftChild != NULL) list.push_back(parent->leftChild);
		if (parent->rightChild != NULL) list.push_back(parent->rightChild);

		if (list.empty()) return;

		parent=list.front();
		list.pop_front();
	}
}

Tree::Tree(int node_num) {
	root=new TreeNode[node_num];
	theSize=node_num;

	char ch='A';

	for (int i=0; i<node_num; ++i) {
		root[i].element=ch+i;
		root[i].leftChild=NULL;
		root[i].rightChild=NULL;
	}
}

Tree::~Tree() {
	if (root!=NULL) delete []root;
}

void Tree::setElement(int i, char theElement) {
	root[i].element=theElement;
}

void Tree::addNodeL(int i, int j) {
	TreeNode *parent=&root[i];
	TreeNode *child=&root[j];

	parent->leftChild=child;
}

void Tree::addNodeR(int i, int j) {
    TreeNode *parent=&root[i];
    TreeNode *child=&root[j];

    parent->rightChild=child;
}

#endif
