// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

//structure for node
struct QueueNode
{
    int data;
    QueueNode* next;
};

class Queue 
{
private:
    QueueNode* front;
    QueueNode* rear;

public:
    //Constructor and Deconstructor
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty();
};

#endif
