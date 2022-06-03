/*Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:

Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. */

// code
Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node* temp = head;
    if(head == NULL){
        return NULL;
    }
    // deleting first node that is head
    if(x == 1){
        temp = temp->next;
        head = temp;
        return head;
        
    }
    
    int count = 2;
    // this while loop will break at 1 position before the node which is to be deleted
    while(temp->next!=NULL && count!=x){
        temp = temp-> next;
        count++;
    }
    // changing the links of the node coming before the todelete node and 
    //storing the next of next to its next pointer.
    //deleting the node
    temp -> next = temp->next->next;
    return head;
}
