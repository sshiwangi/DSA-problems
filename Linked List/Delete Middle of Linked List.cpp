/*
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 1 2 4 5 */

// Function to find the length of the linked list
int length(Node* head){
    Node* temp = head;
    int l = 0;
    while(temp!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    // Find the middle position and change the link
	int l = length(head);
	Node* temp = head;
	int mid = (l/2);
	int pos = 0;
	
	while(temp!=NULL){
	    pos++;
	    if(pos == mid){
	        break;
	    }
	    
	    temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;

}
