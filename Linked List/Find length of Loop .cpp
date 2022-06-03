/* Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not 
and if the loop is present then return the count of nodes in a loop or else return 0. 
C is the position of the node to which the last node is connected. If it is 0 then no loop.
Input:
N = 10
value[]={25,14,19,33,10,21,39,90,58,45}
C = 4
Output: 7 */

// code
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* slow = head;
    Node* fast = head;
    int ans = 1;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next; // move slow pointer 1 step at a time
        fast = fast->next->next; // and fast pointer 2 steps at a time
        if(slow == fast){ // if there is a loop
            slow = slow->next ; // take any pointer and move it 1 step at a time till
            // it comes back to the same position
            while(slow != fast){
                ans++ ; // keep counting the steps
                slow = slow->next ;
            }
            // return the answer
            return ans;
        }
        
    }
    return 0;
}
