#include <iostream>
using namespace std;

struct Stack {
    int array[10];
    int top;

    Stack() {
         top = -1;
    }

    void push(int item);
    int pop();
    bool isFull();
    bool isEmpty();
};

bool Stack::isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

bool Stack::isFull() {
    if(top == 9) {
        return true;
    } else {
        return false;
    }
}

void Stack::push(int item) {
    if(isFull()) {
        cout << "Stack is full.";
    }

    top++;
    array[top] = item;
}

int Stack::pop() {
   if(isEmpty()) {
        cout << "Stack is empty.";
    } 

    int item = array[top];
    top--;
    return item;
}