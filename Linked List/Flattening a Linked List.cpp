/* 
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.) */

// Function to merge two linked list
Node* merge(Node* head1,Node* head2){
       if(head1==NULL)
           return head2;
       if(head2==NULL)
           return head1;
       Node* res;
       if(head1->data<head2->data){
           res=head1;
           res->bottom=merge(head1->bottom,head2);
       }
       else{
           res=head2;
           res->bottom=merge(head1,head2->bottom);
       }
       res->next=NULL;
       return res;
   }
/*  Function which returns the  root of 
    the flattened linked list. */

Node *flatten(Node *root)
{
   // Your code here
    if(root==NULL || root->next==NULL)
        return root;
    return merge(root,flatten(root->next));
}
