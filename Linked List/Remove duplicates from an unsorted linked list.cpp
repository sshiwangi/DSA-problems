/* Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, 
the node which appeared first should be kept, all others duplicates are to be removed.
Example 1:

Input:
N = 5
value[] = {5,2,3,2,4}
Output: 5 2 3 4
*/ 

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        
     // your code goes here
        unordered_set<int> seen;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr!=NULL){
            // if the node is already present in the set
            if(seen.find(curr->data)!=seen.end()){
                // change the link and delete the node
                prev->next = curr->next;
                delete(curr);
            }
            else{
                seen.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }
};
