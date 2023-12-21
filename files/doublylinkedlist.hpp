#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class DoublyLinkedList {
    private:
        struct Node {
            T data;
            struct Node *next;
            struct Node *prev;
        }*start;

        Node* create_node(T data) { 
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        DoublyLinkedList() {
            start = new(struct Node);
            start -> next = NULL;
            start -> prev = NULL;
        }

    void add_begin(T data) {
        Node *new_node = create_node(data);
        Node *temp = start;
        start -> prev = new_node;
        new_node -> next = start;
        new_node -> prev = NULL;
        start = new_node;
    }

    void add_last(T data) {
        Node *new_node = create_node(data);
        Node *lastNode = start;
        while(lastNode -> next != NULL) {
            lastNode = lastNode -> next;
        }
        lastNode -> next = new_node;
        new_node -> prev = lastNode;
        new_node -> next = NULL;
    }

    void del_head() {
        check_notEmpty();
        Node *new_head = start -> next;
        new_head -> prev = NULL;
        delete start;
        start = new_head;
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
