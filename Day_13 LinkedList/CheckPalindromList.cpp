/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {

//          if (!head || !head->next)
//         return true;

//     // Step 1: Find the middle of the linked list
//     ListNode* slow = head;
//     ListNode* fast = head;
//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Step 2: Reverse the second half of the linked list
//     ListNode* prev = nullptr;
//     while (slow) {
//         ListNode* nextNode = slow->next;
//         slow->next = prev;
//         prev = slow;
//         slow = nextNode;
//     }

//     // Step 3: Compare the reversed second half with the first half
//     while (prev) {
//         if (prev->val != head->val)
//             return false;
//         prev = prev->next;
//         head = head->next;
//     }

//     return true;
        
//     }
// };

/*
Simple Method just like array reverse method 

class Solution {
private:
     bool checkPalindrome(vector<int>arr){
        
        int s = 0;
        int n = arr.size();
        int e = n-1;
        while(s<=e){
            if(arr[s]!=arr[e]){
                return false;
            }
                s++;
                e--;
        }
            return 1; 
     }
public:
    bool isPalindrome(ListNode* head) {
        vector<int>arr;

        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        return checkPalindrome(arr);
    }  
 };

 */



class Solution{
    
    private:
    
    // Midddle of the linked list  
      ListNode* getMid(ListNode*head){
          
          ListNode*slow = head;
          ListNode*fast = head;
         
         if(fast!=NULL && fast->next!=NULL){
             fast = fast ->next->next;
             slow = slow ->next;
         }
        
        return slow;
    
      }
    
    // Write the revrsre function 
    ListNode* reverse(ListNode*head){
        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*forward = NULL;
        
        while(curr!=NULL){
            forward =  curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
         }
      return prev;
    }
    
    
    public: 
    bool isPalindrome(ListNode*head){
        
        if(head->next== NULL){
            return true;
        }
        
        // Step 1 Find Middle element 
        ListNode*middle = getMid(head);
        
        
        //Step 2  Reverse the list after middle element
       ListNode*temp = middle->next;
        middle->next = reverse(temp);
        
        // Compare the list 
        ListNode*head1 = head;
        ListNode*head2 = middle->next;
        
        while(head2!=NULL){
            
            if(head1->val!=head2->val){
            return false;
            }
            
            head1 = head1->next;
            head2  = head2->next;
        
        }
          return true;
    }
    
};

