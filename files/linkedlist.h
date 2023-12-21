#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class LinkedList {
    private:
        struct Node {
            T data;
            struct Node *next;
        }*start;

        Node* create_node(T data) { 
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        LinkedList() {
            start = new(struct Node);
        }

    void add_begin(T data) {
        Node *new_node = create_node(data);
        Node *temp = start;
        start = new_node;
        new_node -> next = temp;
    }

    void add_last(T data) {
        Node *new_node = create_node(data);
        Node *temp = start;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_node;
        new_node -> next = NULL;
    }

    void del_head() {
        check_notEmpty();
        Node *head = start -> next;
        delete start;
        start = head;
    }

    void del_tail() {
        check_notEmpty();
        if(start -> next == NULL) {
            delete start;
            return;
        }

        Node *second_last = start;
        while (second_last -> next -> next != NULL) {
        second_last = second_last -> next;
        }
        second_last -> next = NULL;
    }

    void check_notEmpty() {
        if (start == NULL) {
            cout << "Empty!";
            return;
        }
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

        int count = -1;
        Node *head = start;
        while (head != NULL) {
            head = head -> next;
            count ++;
        }
        return count;
    }

    void show() {
        check_notEmpty();

        Node *s = start;
        while (s -> next != NULL) {
            cout << s -> data << " ";
            s = s -> next;
        }
    }
};
