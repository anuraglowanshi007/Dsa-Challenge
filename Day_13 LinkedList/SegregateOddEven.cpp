// Segregate Odd Even list 

//with extra space 
// t/c - 0(n)
// s/c - 0(n)

ListNode* oddEvenList(ListNode* head) {
        vector<int>arr;

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*temp = head;

        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        // for last element 
        if(temp!=NULL){
            arr.push_back(temp->val);
        }

        temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
         // for last element 
        if(temp!=NULL){
            arr.push_back(temp->val);
        }

        temp  = head;
        int i = 0;
        while(temp!=NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }


//withOut extra space  Odd even 
// t/c - 0(n)
// s/c - 0(1)

ListNode* oddEvenList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*odd = head;
        ListNode*even = head->next;
        ListNode*temp = even;

        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = temp;   // to connect after the odd or  even 

        return head;

    }