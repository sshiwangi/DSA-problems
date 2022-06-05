/* Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.
Note: The list elements are not necessarily distinct.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection. */

Node* findIntersection(Node* head1, Node* head2)
{
    // make and ans node
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(head1!=NULL && head2!=NULL){
        // if head1 and head2 are equal then store head1 in answer
        if(head1->data == head2->data){
            temp->next = head1;
            head1 = head1->next;
            head2 = head2->next;
            temp = temp -> next;
        }
        // otherwise move that pointer which is smaller
        else if(head1->data< head2->data){
            head1 = head1->next;
        }
        else if(head1->data> head2->data){
            head2 = head2->next;
        }
    }
    //return our answer
    return ans->next;

    
}
