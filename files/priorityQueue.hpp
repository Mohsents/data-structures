#include <iostream>
using namespace std;

struct Node {
    int data;
  	int priority;
    struct Node  *next;
}*front = NULL;

void insert(int item, int priority) {
    Node *node, *temp;
    
    node = new Node;
    node -> data = item;
    node -> priority = priority;
    
    if (front == NULL || priority < front -> priority) {
          node -> next = front;
          front = node;
        } else {
            temp = front;
            while (temp -> next != NULL && temp -> next -> priority <= priority)
                        temp = temp -> next;
                        node -> next = temp -> next;
                        temp -> next = node;
        }
}

void remove() {
    if(front == NULL)
       cout << "Underflow";
    else {
          Node *node = front;
          front = front -> next;
          free(node);
        }
}

void show() {
   Node *node = front;   

   if (front == NULL)
       cout << "empty";
   else {	
        cout << "Item      Priority\n";
        cout << "------------------\n";
        while(node != NULL) {
              cout << node -> data << "               " << node -> priority << endl;
              node = node -> next;
        }
   }
}