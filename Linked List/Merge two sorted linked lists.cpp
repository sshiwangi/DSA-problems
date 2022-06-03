/*Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
EXAMPLE:
Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40. */

//Recursive Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1 == NULL){
        return head2;
    }
    
    if(head2 == NULL){
        return head1;
    }
    // create a result node
    Node* result;
    
    if(head1->data < head2->data){
        // store head1 in the result and pass its next and head2 to the function and store it in the next of result
        result = head1;
        result -> next = sortedMerge(head1->next, head2);
    }
    else{
        result = head2;
        result -> next = sortedMerge(head1, head2->next);
    }
    // lastly return the result
    return result;
}  
