/* Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // make two pointers fast and slow
        Node* fast = head;
        Node* slow = head;
        // move the slow pointer 1 step and fast 2 step until fast and next of fast is not equal to null
        while(fast!= NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            // if fast becomes equal to slow , then it has a cycle
            if(fast == slow){
                return true;
            }
            
        }
        return false;
        
        
    }
};
