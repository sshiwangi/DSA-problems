/* Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed*/
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { // we will reverse the first k nodes with iterative method using 3 pointers and 
    //the rest by recursive method
        // declare 3 pointers
        node* prevptr = NULL;
        node* currptr = head;
        node* nextptr;
        int count = 0;
        while(currptr!=NULL && count < k){
            nextptr = currptr -> next;
            currptr-> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count ++;
        }
        // if nextptr is not equal to null, to join the reversed set of nodes 
        //make the next of head point to the head of the set ofnodes we reversed using recursive method
        if(nextptr!=NULL){
            head -> next = reverse(nextptr, k);
        }
        // lastly return the prev pointer as it will be the new head of the reversed linked list
        return prevptr;
    }
};
