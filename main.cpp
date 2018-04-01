#include <iostream>
#include "TreeNode.h"
#include "Tree.h"
using namespace std;

int main() {
	Tree<char> tree(5);

	if (!tree.empty()) {
		cout<<"The size is "<<tree.size()<<endl;
	}

    tree.setElement(0,'A');
    tree.setElement(1,'B');
    tree.setElement(2,'C');
    tree.setElement(3,'D');
    tree.setElement(4,'E');

	tree.addNodeL(0,1);
	tree.addNodeR(0,2);
	tree.addNodeL(1,3);
	tree.addNodeR(1,4);

	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();

	cout<<"After re-setting the elements:"<<endl;
	tree.setElement(0,'a');
	tree.setElement(1,'b');
	tree.setElement(2,'c');
	tree.setElement(3,'d');
	tree.setElement(4,'e');

    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
	tree.levelOrder();

	return 0;
}
