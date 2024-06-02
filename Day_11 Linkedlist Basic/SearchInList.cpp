#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* constructLL(vector<int>& arr) {
    if (arr.empty()) return NULL; // Handle empty array case

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

bool searchKey(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    // Example input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    vector<int> input = {1, 2, 3, 4, 5};
    Node* head = constructLL(input);

    // Traversing the linked list
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Searching for keys
    int key = 3;
    if (searchKey(head, key)) {
        cout << "Key " << key << " is found in the linked list." << endl;
    } else {
        cout << "Key " << key << " is not found in the linked list." << endl;
    }

    key = 6;
    if (searchKey(head, key)) {
        cout << "Key " << key << " is found in the linked list." << endl;
    } else {
        cout << "Key " << key << " is not found in the linked list." << endl;
    }

    return 0;
}
