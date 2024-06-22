//utility function to check presence of intersection

node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end())
         return head2;
        head2 = head2->next;
    }
    return NULL;

}

//--optimal Approach 
node*intersection(node*headA,node*headB){
    node*curr=headA; 
    int a = 0;
    int b = 0;
    whlie(curr!=NULL){
        a++;
        curr=curr->next;
    }
    currB=headB;
    while(currB!=NULL){
        b++;
        currB=currB->next;
        }
        int diff = abs(a-b);
        if(a<b){
            while(diff--){
                headB=headB->next;
            }
        }else{
            while(diff--){
                headA=headA->next;
                }
        }
        while(headA!=NULL&&headB!=NULL){
            if(headA==headB){
                return headA;
                }
                headA=headA->next;
                headB=headB->next;
                }
                return NULL;

}
