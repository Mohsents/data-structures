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
using namespace std;

// void show_array(int array[], int lenght) {
//     for (int i = 0; i <= lenght; i++) {
//         cout << "\t" + to_string(array[i]);
//     }
// }

int main() {
    // Define unsorted array
    // int array[8] = {1,3,6,4};
    // int sorted_array[15] = {1,2,3,6,8,12,15,22,33,46};
    // int length = ssize(sorted_array);
    // int key = -1;

    // int res = linear_search(array,length, key);
    //binary_search(sorted_array, 0, length - 1, key);

    /* if(res == -1) {
        cout << "item not found!";
    } else {
        cout << "item found in index: " + to_string(res);
    }
    */

   //del(sorted_array, length, key);
   //show_array(sorted_array, 8);

   // insert_unsorted(array, length, 4, 100);
   // show_array(array, length);

    //insert_sorted(sorted_array, length, 10, key);
    //show_array(sorted_array, length);

    // int a[7] = {-1,-1,3,4,5,6,7};
    // int b[2] = {1,2};

    // merge_sorted(a, b, 5, 2);

    // show_array(a, 7);

    // int arr[] = {5,6,7,8,9,1,2,3,4};
    // int key = 4;
    // int res = binary_search_unsorted(arr, 9, key);
    // cout << "Item found in index:" + to_string(res);

    // struct Queue *queue;
    // queue = create_queue(10);
    // add(queue, 45);
    // add(queue, 232);
    // add(queue, 67);

    // cout << endl;

    // cout << "size: " << queue -> size << endl;
    // cout << "capacity: " << queue -> capacity << endl;

    // CircularQueue queue(4);
    // queue.add(5);
    // queue.add(7);
    // queLinkedListue.add(3);
    // queue.show();
    // cout << endl;
    // queue.del();
    // cout << endl;
    // queue.show();
    // cout << endl;
    // queue.add(6);
    // queue.add(4);
    // queue.show();
    // cout << endl;
    // queue.add(9);
    // cout << endl;

    // Stack stack = Stack();
    // stack.push(3);
    // stack.push(2);
    // stack.push(5);

    // int res = stack.pop();
    // cout << to_string(res);

    // LinkedList<int> list;
    // list.add_begin(1);
    // list.add_begin(2);
    // list.add_begin(3);
    // list.add_last(100);
    // list.add_last(200);
    // list.add_last(300);
    // list.del_head();
    // list.del_tail();
    // list.reverse();
    // list.show();
    // cout << "List length = " << list.get_length() << "\n";

    // DoublyLinkedList<int> list;
    // list.add_begin(1);
    // list.add_begin(2);
    // list.add_begin(3);
    // list.add_last(100);
    // list.add_last(200);
    // list.add_last(300);
    // list.del_head();
    // list.del_head();
    // list.del_tail();
    // list.reverse();
    // list.delete_at(2);
    // list.delete_at(5);
    // list.show();
   // cout << "List length = " << list.get_length() << "\n";

//    CircularDoublyLinkedList<int> list;
//     list.add_bein(1);
//     list.add_begin(2);
//     list.add_begin(3);
//     list.add_begin(4);
//     list.add_begin(5);
//     list.add_last(100);
//     list.add_last(200);
//     list.add_last(300);
    // list.del_head();
    // list.del_tail();
    // list.show();
    // cout << "\n";
    // list.delete_at(2);
    // list.delete_at(5);
    // list.reverse();
    // list.show();
    // cout << "\n";
    // cout << "List length = " << list.get_length() << "\n";

    //BinaryTree<int> tree;
    //tree.create_tree(1);

    //cout << "Tree heigth: " << tree.get_height(tree.root) << "\n";
    //cout << "Tree max value: " << tree.get_max(tree.root) << "\n";
    //cout << "Tree leaf count: " << tree.get_count_leaf(tree.root) << "\n";
    //cout << "Tree node count: " << tree.get_count(tree.root) << "\n";
    //tree.show(tree.root);
    //cout << "\n";
    //tree.delete_tree(tree.root);
    //cout << "In-order teraversal:";
    //tree.in_order_traversal(tree.root);

    //cout << endl;
    //cout << "Pre-order teraversal:";
    //tree.pre_order_teraversal(tree.root);

    //cout << endl;
    //cout << "Level-order traversal:";
    //tree.level_order_traversal(tree.root);
    //cout << endl;

    //int item = 5;
    //cout << "Level of item " << item << " is: " << tree.find_level(tree.root, item) << endl;
    //cout << "Ancestors of item " << item << " is: " << tree.find_ancestors(tree.root, item) << endl;

    //cout << "Is complete Tree: " << tree.is_complete_tree(tree.root) << endl;

    //int a = 5;
    //int b = 3;
    //cout << "LCA items " << a << " and " << b << ": " << tree.find_LCA(tree.root, a, b) -> data << endl;

    //cout << "In-order Traversal threaded tree: ";
    //tree.in_order_threaded_travers(tree.root);
    //cout << endl;

    //cout << "Sum of all root to leaf paths: " << tree.root_to_leaf_sum(tree.root, 0) << endl;

    BSTTree<int> bsttree;
    bsttree.insert(bsttree.root, 10);
    bsttree.insert(bsttree.root, 5);
    bsttree.insert(bsttree.root, 6);
    bsttree.insert(bsttree.root, 8);
    bsttree.insert(bsttree.root, 20);
    bsttree.insert(bsttree.root, 98);
    bsttree.insert(bsttree.root, 12);
    bsttree.insert(bsttree.root, 23);
    bsttree.insert(bsttree.root, 45);
    bsttree.insert(bsttree.root, 50);

    cout << "In-order Traversal: ";
    bsttree.inorder_travers(bsttree.root);
    cout << endl;

    int key = 20;
    cout << "Is item " << key << " founded?: " << bsttree.search(bsttree.root, key) << endl;

    return 0;
}
