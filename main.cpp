/*
* Main.cpp
* Purpose: To convert decimal inputs to binary code using a linked list
* Input: decimal value
* Output: Binary code
* Process: Stack and queue header files to define structures and classes
*          use functions to seperate integer and decimal values
*          use functions to calculate the binary code for integer and decimal
*/
#include <iostream>
#include <cmath>
#include "Stack.h"
#include "Queue.h"

using namespace std;

// Function to convert and display integer part using a stack
void convertBinary(int number) 
{
    Stack stack;

    if (number == 0)
    {
        stack.push(0);
    }
    else
    {
        while (number > 0)
        {
            int remainder = number % 2;
            stack.push(remainder);
            number = number / 2;
        }
    }

    while (!stack.isEmpty())
    {
        cout << stack.pop();
    }
}

// Function to convert and display fractional part using a queue
void convertFracBinary(double fraction) 
{
    Queue queue;
    int count = 0;

    while (fraction > 0 && count < 8) 
    {
        fraction = fraction * 2;
        int bit = (int)fraction;
        queue.enqueue(bit);
        fraction = fraction - bit;
        count++;
    }

    if (!queue.isEmpty()) 
    {
        cout << ".";
        while (!queue.isEmpty())
        {
            cout << queue.dequeue();
        }
    }
}

int main() 
{
    //Program Description
    cout << "This program will convert any decimal value to a binary code." << endl;

    //Variable Declaration
    double decimalNumber;
    char choice;

    // Ask the user to enter a decimal number
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    // Split into integer and fractional parts
    int integerPart = (int)decimalNumber;
    double fractionalPart = decimalNumber - integerPart;

    cout << "Binary: ";
    convertBinary(integerPart);
    convertFracBinary(fractionalPart);
    cout << endl;

    // Ask if user wants to convert another number
    cout << "Would you like to convert another number? (y/n): ";
    cin >> choice;

    while (choice == 'y' || choice == 'Y') 
    {
        // Ask the user to enter a decimal number
        cout << "Enter a decimal number: ";
        cin >> decimalNumber; 

        // Split into integer and fractional parts
        int integerPart = (int)decimalNumber; 
        double fractionalPart = decimalNumber - integerPart; 

        cout << "Binary: ";
        convertBinary(integerPart); 
        convertFracBinary(fractionalPart); 
        cout << endl;  

        cout << "Would you like to convert another number? (y/n): ";
        cin >> choice;
        
    }

    return 0;
}

/*
* Sample Output:
Enter a decimal number: 12.564
Binary: 1100.100100

Sample 2:
This program will convert any decimal value to a binary code.
Enter a decimal number: 12.365
Binary: 1100.01011101
Would you like to convert another number? (y/n): n

Sample 3:

This program will convert any decimal value to a binary code.
Enter a decimal number: 12.365
Binary: 1100.01011101
Would you like to convert another number? (y/n): y
Enter a decimal number: 44.8930
Binary: 101100.11100100
Would you like to convert another number? (y/n): n


*/