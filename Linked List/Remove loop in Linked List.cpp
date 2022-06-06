/* Given a linked list of N nodes such that it may contain a loop.
Remove the loop from the linked list, if it is present.  */

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL && head->next == NULL){
            return;
        }
        Node* slow = head;
        Node* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;
        
        while(fast && fast->next){
            if(slow == fast)break;
            slow = slow->next;
            fast = fast->next->next;
        
        }
    
        if(slow == fast){
            slow = head;
            // case for when the loop starts at head
            if(slow == fast){
                while(fast->next!=slow){
                    fast = fast->next;
                }
            }else{
                while(slow->next!=fast->next){
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast ->next = NULL;
        }
    }
};
