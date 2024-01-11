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
#include "priorityQueue.hpp"
#include "graph.hpp"
using namespace std;

int main() {
	Graph g;
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 5);
	g.addEdge(5, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	g.DFS(2);

	return 0;
}
