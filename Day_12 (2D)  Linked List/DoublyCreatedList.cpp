#include <iostream>
#include <vector>

// Definition for a doubly linked list node.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to construct a doubly linked list from a vector of integers.
Node* constructDLL(std::vector<int>& arr) {
    // If the array is empty, return nullptr
    if (arr.empty()) return nullptr;

    // Create the head node
    Node* head = new Node(arr[0]);
    Node* temp = head;

    // Iterate through the array starting from the second element
    for (int i = 1; i < arr.size(); ++i) {
        // Create a new node for the current element
        Node* curr = new Node(arr[i]);

        // Link the new node with the previous node
        curr->prev = temp;
        temp->next = curr;

        // Move the temp pointer to the current node
        temp = curr;
    }

    // Return the head of the doubly linked list
    return head;
}

// Function to print the doubly linked list from head to tail
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to print the doubly linked list from tail to head
void printListReverse(Node* head) {
    if (!head) return;
    Node* tail = head;
    // Move to the end of the list
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Print from tail to head
    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    // Construct the doubly linked list
    Node* head = constructDLL(arr);

    // Print the list from head to tail
    std::cout << "List from head to tail: ";
    printList(head);

    // Print the list from tail to head
    std::cout << "List from tail to head: ";
    printListReverse(head);

    return 0;
}
