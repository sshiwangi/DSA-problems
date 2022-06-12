/* Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time. */

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
 
 Node* curr = head;
 Node* nextp = curr->next;
 while(nextp!=NULL){
     // if the curr and next are equal, change the linkes that is make the next of curr point 
     // to the next of nextp
    if(curr->data == nextp->data) {
        curr->next = nextp->next;
        nextp = nextp->next;
    }
    // else do curr = next and move next pointer one step ahead too 
    else{
        curr = nextp;
        nextp = nextp->next;
    }
    
 }
 // lastly return head;
 return head;
}