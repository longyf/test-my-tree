#include <iostream>
#include "TreeNode.h"
#include "Tree.h"
using namespace std;

int main() {
	Tree tree(5);

	if (!tree.empty()) {
		cout<<tree.size()<<endl;
	}

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
