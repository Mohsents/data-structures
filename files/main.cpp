#include <iostream>
#include "arrays.h"
#include "queue.h"
#include "circularQueue.h"
#include "stack.h"
#include "linkedlist.h"
#include "doublylinkedlist.hpp"
#include "circularDoublyLinkedList.hpp"
#include "binaryTree.hpp"
#include "BSTTree.hpp"
#include "AVLTree.hpp"
#include "HeapTree.hpp"
using namespace std;

int main() {
	HeapTree htree;
	htree.createMinHeapTree(6);
	htree.addMin(1);
	htree.addMin(2);
	htree.addMin(3);
	htree.addMin(4);
	htree.addMin(5);
	htree.addMin(6);
	cout << "Min Heap Tree: ";
	htree.showMinTree();
	cout << endl;

	htree.createMaxHeapTree(8);
	htree.addMax(4);
	htree.addMax(3);
	htree.addMax(2);
	htree.addMax(6);
	htree.addMax(5);
	htree.addMax(8);
	htree.addMax(7);
	htree.addMax(1);
	cout << "Max Heap Tree: ";
	htree.showMaxTree();

	cout << endl;
	cout << "Delete min tree root: ";
	htree.minRootRemove();
	htree.showMinTree();

	cout << endl;
	cout << "Delete max tree root: ";
	htree.maxRootRemove();
	htree.showMaxTree();

	return 0;
}
