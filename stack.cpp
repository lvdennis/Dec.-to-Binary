// stack.cpp
#include <iostream>
#include "Stack.h"
using namespace std;

// Initialization for stack
Stack::Stack()
{
    top = NULL;
}

// Deallocating all the stacks
Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// Push
void Stack::push(int value)
{
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop
int Stack::pop()
{
    if (isEmpty()) 
        return -1;

    StackNode* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

// Checks if the stack is empty
bool Stack::isEmpty() 
{
    return top == NULL;
}


