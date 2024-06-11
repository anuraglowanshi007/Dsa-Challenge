// InsertAt Begining and InsertAt End

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to insert a node at the beginning of the linked list.
Node* insertAtBegining(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        return temp;
    }
    temp->next = head;
    head = temp;
    return head;
}

// Function to insert a node at the end of the linked list.
Node* insertAtEnd(Node* head, int x) {
    Node* newnode = new Node(x);
    if (head == NULL) {
        return newnode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// Utility function to print the linked list.
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Inserting nodes at the beginning
    head = insertAtBegining(head, 5);
    head = insertAtBegining(head, 2);
    printList(head); // Output: 2 5

    // Inserting nodes at the end
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 6);
    printList(head); // Output: 2 5 9 6

    return 0;
}
