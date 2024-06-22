// pair sum 

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>> final;
        
        Node* start = head;
        Node* last = head;
        while(last->next != NULL){
            last = last->next;
        }
        while(start->data < last->data){
            if(start->data + last->data == target){
                final.push_back(make_pair(start->data , last->data));  
                start = start->next;
                last = last->prev;
            }
            else if(start->data + last->data >target){
                last = last->prev;
            }
            else{
                start = start->next;
            }
        }
        return final;
    }