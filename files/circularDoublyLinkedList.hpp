#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class CircularDoublyLinkedList {
    private:
        struct Node {
            T data;
            struct Node *next;
            struct Node *prev;
        }*start,*end;

        Node* create_node(T data) { 
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        CircularDoublyLinkedList(){
            start = end = NULL;
        }

        void add_begin(T data) {
        Node *new_node = create_node(data);

        if(start == NULL) {
            start = end = new_node;
            new_node -> next = start;
            new_node -> prev = start;
        } else {
            new_node -> next = start;
            start -> prev = new_node;
            start = new_node;
            start -> prev = end;
            end -> next = start;
        }
    }

        void add_last(T data) {
            Node *new_node = create_node(data);
            Node *lastNode = start;
            while(lastNode -> next != start) {
                lastNode = lastNode -> next;
            }
            lastNode -> next = new_node;
            new_node -> prev = lastNode;
            new_node -> next = start;
            start -> prev = new_node;
            end = new_node;
    }

        void del_head() {
            check_notEmpty();
            Node *new_head = start -> next;
            new_head -> prev = end;
            start = new_head;
            end -> next = start;
    } 

        void del_tail() {
            check_notEmpty();
            if(start -> next == start) {
                delete start;
                return;
            }

            Node *new_end = end -> prev;
            new_end -> next = start;
            start -> prev = new_end;
            end = new_end;
    }

        void check_notEmpty() {
            if (start == NULL) {
                cout << "Empty!";
                return;
            }
     }

        void delete_at(int pos) {
            check_notEmpty();

            Node *node = start;
            for(int i = 1; i < pos; i++) {
                node = node -> next;
            }

            Node *prev_node = node -> prev;
            Node *next_node = node -> next;
            prev_node -> next = next_node;
            next_node -> prev = prev_node;
            delete node;
    }

        void reverse() {
            Node* current = start;
            Node *prev = NULL, *next = NULL;
    
            while (current != NULL) {
                // Store next
                next = current -> next;
                // Reverse current node's pointer
                current -> next = prev;
                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            start = prev;
    }

        int get_length() {
            if(start == NULL) {
                return 0;
            }

            int count = 0;
            Node *head = start;
            while (head -> next != start) {
                head = head -> next;
                count++;
            }
            return count;
    }

        void show() {
            check_notEmpty();

            Node *s = start;
            do {
                cout << s -> data << " ";
                s = s -> next;
            } while(s -> next != start);
    }
};
