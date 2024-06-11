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

int getCount(Node* head) {
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main() {
    // Custom test cases
    vector<vector<int>> testCases = {
        {3, 1, 2, 3},    // Test case 1
        {5, 4, 5, 6, 7, 8}  // Test case 2
        // Add more test cases if needed
    };

    // Process each test case
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> arr = testCases[i];
        Node* head = constructLL(arr);
        cout << "Test Case " << i+1 << ":\n";
        cout << "Linked List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nCount of nodes: " << getCount(head) << endl;
        cout << endl;
    }

    return 0;
}
