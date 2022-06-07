/* Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7 */

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* temp = head;
        Node* prev = NULL; 
        // go to the kth node and make it new head
        while(k and temp){
            prev = temp;
            temp = temp->next;
            k--;
            
        }
        if(temp == NULL){
            return head;
        }
        // make the prev point to null
        prev->next = NULL;
        Node* newHead = temp;
        // go to the last node of the linked list
        while(temp->next){
            temp = temp->next;
        }
        // and make its next point to the head 
        temp->next = head;
        // return new head
        return newHead;
        
    }
};
