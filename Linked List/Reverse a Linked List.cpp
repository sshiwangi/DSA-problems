class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        // call recursion for the next of head, it will reverse the node except head
        Node* newhead = reverseList(head->next);
        // after that reverse the link of head and its next too
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    
};
