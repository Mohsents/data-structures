#include <iostream>
using namespace std;

struct CircularQueue {
    int *a;
    int s;
    int front;
    int rear;

    CircularQueue(int size) {
        a = new int[size];
        s = size;
        front = -1;
        rear = -1;
    }

    void add(int item);
    int del();
    void show();
    bool isEmpty();
};

void CircularQueue::add(int item) {
    if((front == 0 && rear == s - 1) || (rear == front - 1)){
        cout << "Full!";
        return;
    } else if(front == -1) {
        front = 0;
        rear = 0;
        a[rear] = item;
    } else if(rear == s - 1 && front != 0) {
        // Trun to head
        rear = 0;
        a[rear] = item;
    } else {
        rear++;
        a[rear] = item;
    }
}

int CircularQueue::del() {
    if(isEmpty()) {
        cout << "Empty!";
        return -1;
    }

    int item = a[front];
    a[front] = -1;
    if(front == rear) {
        front = -1;
        rear = -1;
    } else if (front == s - 1) {
        front = 0;
    } else {
        front++;
    }
    return item;
}

void CircularQueue::show() {
    if(isEmpty()) {
        cout << "Empty!";
        return;
    }

    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            cout << a[i] << " ";
        }
    } else {
        for (int i = front; i <= s - 1; i++) {
            cout << a[i] << " "; 
        }
        for (int i = 0; i <= rear; i++) {
            cout << a[i] << " "; 
        }
   }
}

bool CircularQueue::isEmpty() {
    if(front == -1) {
        return true;
    } else {
        return false;
    }
}
