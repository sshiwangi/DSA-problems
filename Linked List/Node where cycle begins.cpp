/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter. */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){ 
        slow = slow->next; // move slow pointer 1 step at a time
        fast = fast->next->next; // and fast pointer 2 steps at a time
            if(slow == fast){// if there is a loop
                fast = head;
                while(fast!=slow){
                     fast = fast->next;
                     slow = slow->next;
                }
                return fast;
                break;
            }
            
        }
        // if there is not a loop then return Null
        return NULL;
        
       
    }
        
};
