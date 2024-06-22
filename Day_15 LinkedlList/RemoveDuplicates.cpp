 // Remove Duplicates form list 

 Node* removeDuplicates(struct Node* head) {
    // Check if the list is empty
    if (head == NULL) return head;
    
    Node* temp = head;

    // Traverse the list
    while (temp != NULL && temp->next != NULL) {
        // Check if the current node has the same data as the next node
        if (temp->data == temp->next->data) {
            // Duplicate found, remove it
            Node* duplicate = temp->next;
            temp->next = duplicate->next;

            if (duplicate->next != NULL) {
                duplicate->next->prev = temp;
            }
            
            free(duplicate);
        } else {
            // Move to the next node only if no deletion is made
            temp = temp->next;
        }
    }

    return head;
}