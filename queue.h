#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue {
  int *arr;
  int front;
  int rear;
  int size;
  unsigned capacity;
};

struct Queue* create_queue(unsigned capacity) {
    struct Queue* queue;
    queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> rear = capacity - 1;      
    queue -> size = 0;
    queue -> arr = new int[queue -> capacity];
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue -> size == 0);
}

int isFull(struct Queue* queue) {
    return (queue -> capacity == queue -> size);
}

void add(struct Queue* queue, int item) {
    if(isFull(queue)) return;

    queue -> rear = (queue -> rear++) % queue -> capacity;
    queue -> arr[queue -> rear] = item;
    queue -> size++;
    cout << "Item " + to_string(item) + " added." << endl;
}

int delete_item(struct Queue* queue) {
    if(isEmpty(queue)) return -1;

    int item = queue -> arr[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> size--;
    return item;
}