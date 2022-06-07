/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1. */

class Solution{
  public:
  // Function to reverse a linked list
    struct Node* reverseList(struct Node *head){
        Node* cur=head;
        Node* prv=NULL;
        Node* nextptr;
        while(cur!=NULL){
            nextptr=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nextptr;
        }
        return prv;
    }
    //Function to find the middle of the linked list
    struct Node* middle(struct Node *head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
        }
        return slow;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {  
        if(head==NULL){
            return true;
        }
        Node* mid=middle(head);
        Node* last=reverseList(mid); // 5->4->3 , last = 5
        Node* curr=head; // 1->2->3->4->5  , curr = 1
        // Move till the middle of the linked list from the last
        while(last!=NULL){
            if(last->data!=curr->data){
                return false;
            }
            last=last->next;
            curr=curr->next;
        }
        return true;

    }
};
