/* 
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8. */

//Function to find the length of the linked list
int length(Node* head){
    Node* temp = head;
    int l = 0;
    while(temp!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int l = length(head);
       Node* temp = head;
       int count = 0;
       // if the given position doesnot exist then return -1;
       if(n>l){
           return -1;
       }
       // otherwise traverse in the linked list and if count becomes equal to the position
       // from start which is l-n+1 then return data of temp;
       else{
           while(temp!=NULL){
               count++;
               if(count == l-n+1){
                   return temp->data;
               }
               temp = temp->next;
           }
       }
}
