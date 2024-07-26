// Include necessary libraries
#include <iostream>
using namespace std;

// Define Stack class
class Stack {
    // Pointer to an array that stores elements of the stack
    int* arr;
    // Index of the top element in the stack
    int top;
    // Maximum size of the stack
    int capacity;

public:
    // Constructor to initialize the stack
    Stack(int size)
    {
        // Allocate memory for the stack
        arr = new int[size];
        // Set the maximum size of the stack
        capacity = size;
        // Initialize the top of the stack as -1 indicating
        // the stack is empty
        top = -1;
    }

    // Destructor to deallocate memory
    ~Stack() { delete[] arr; }

    // Function to add an element x in the stack
    void push(int x)
    {
        // Check if the stack is full
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        cout << "Pushing " << x << "\n";
        // Add element and increment top
        arr[++top] = x;
    }

    // Function to remove an element from the stack
    int pop()
    {
        // Check if the stack is empty
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        // Remove element and decrement top
        return arr[top--];
    }

    // Function to return the top element of the stack
    int peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            return -1;
    }

    // Function to return if the stack is empty
    bool isEmpty() { return top == -1; }

    // Function to return if the stack is full
    bool isFull() { return top == capacity - 1; }
};

// Main function
int main()
{
    // Create a stack of size 3
    Stack stack(3);

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print the top element of the stack
    cout << "The top element is " << stack.peek() << endl;
    // Pop an element from the stack and print it
    cout << "Popping " << stack.pop() << endl;
    // Print the top element of the stack
    cout << "The top element is " << stack.peek() << endl;

    // Pop all elements from the stack
    stack.pop();
    stack.pop();

    // Check if the stack is empty and print the result
    if (stack.isEmpty()) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "The stack is not empty" << endl;
    }

    return 0;
}




// include<bits/stdc++.h>

// using namespace std;
// class Stack {
//   int size;
//   int * arr;
//   int top;
//   public:
//     Stack() {
//       top = -1;
//       size = 1000;
//       arr = new int[size];
//     }
//   void push(int x) {
//     top++;
//     arr[top] = x;
//   }
//   int pop() {
//     int x = arr[top];
//     top--;
//     return x;
//   }
//   int Top() {
//     return arr[top];
//   }
//   int Size() {
//     return top + 1;
//   }
// };
// int main() {

//   Stack s;
//   s.push(6);
//   s.push(3);
//   s.push(7);
//   cout << "Top of stack is before deleting any element " << s.Top() << endl;
//   cout << "Size of stack before deleting any element " << s.Size() << endl;
//   cout << "The element deleted is " << s.pop() << endl;
//   cout << "Size of stack after deleting an element " << s.Size() << endl;
//   cout << "Top of stack after deleting an element " << s.Top() << endl;
//   return 0;
// }