// Delete all occurence of key in list 

void deleteAllOccurOfX(Node** head_ref, int x) {
    // Handle the case where the head node itself contains the key
    while (*head_ref != nullptr && (*head_ref)->data == x) {
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        delete temp;
    }

    // If the list becomes empty after removing all key occurrences from the head
    if (*head_ref == nullptr) return;

    // Traverse the list and delete nodes with the given key
    Node* current = *head_ref;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == x) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}