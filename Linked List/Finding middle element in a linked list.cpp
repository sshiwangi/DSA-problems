/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3. */

//code
class Solution{
    public:
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
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        
      int l = length(head);
	    Node* temp = head;
	    int mid = (l/2);
	    int pos = 0;
	    if(head->next == NULL){
	        return head->data;
	    }
	
	    while(temp!=NULL){
	        pos++;
	        if(pos == mid){
	            break;  
	        }
	        temp = temp->next;
	    }
	    return temp->next->data;
    }
};
