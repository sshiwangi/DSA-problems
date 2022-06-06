/*Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Example 1:

Input:
LinkedList = 1->2->4
key = 3
Output: 1 2 3 4
Explanation: The new element is inserted
after the current middle element in the
linked list. */

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
//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	// Find the middle position and change the link
	int l = length(head);
	Node* n = new Node(x);
	Node* temp = head;
	int mid = (l+1)/2;
	int pos = 0;
	
	while(temp!=NULL){
	    pos++;
	    if(pos == mid){
	        break;
	    }
	    
	    temp = temp->next;
	}
	n->next = temp->next;
	temp->next = n;
	return head;
}
