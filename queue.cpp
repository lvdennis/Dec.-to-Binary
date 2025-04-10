// queue.cpp
#include <iostream>
#include "Queue.h"
using namespace std;

// empty queue
Queue::Queue() 
{
    front = NULL;
    rear = NULL;
}

// free memory
Queue::~Queue() 
{
    while (!isEmpty())
    {
        dequeue();
    }
}

// Enqueue - adds a node to the end (rear)
void Queue::enqueue(int value) {
    QueueNode* newNode = new QueueNode;
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// removes node from front
int Queue::dequeue()
{
    if (isEmpty()) return -1;

    QueueNode* temp = front;
    int value = temp->data;
    front = front->next;
    delete temp;
    return value;
}

// Checks if the queue is empty
bool Queue::isEmpty()
{
    return front == NULL;
}


