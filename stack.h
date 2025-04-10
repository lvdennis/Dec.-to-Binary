// Stack.h

#ifndef STACK_H
#define STACK_H

//Structure for traverse from node
struct StackNode
{
    int data; //store binary number data
    StackNode* next;
};

//class for linked list
class Stack 
{

private:
    StackNode* top;

public:
    //Constructor and Deconstructor
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty();
};

#endif
