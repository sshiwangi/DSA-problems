/*You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list. 
Example 1:

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.

Expected Time Complexity : O(1)
Expected Auxilliary Space : O(1)*/

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // we can delete by making a pointer pointing to null and make it move 1 step at a time until it reaches the node to be deleted and then simply change the links
      // but the time complexity is given to be 0(1) so this method will give TLE
      // Instead just store the data of the next of del node in the place of del node.
       del->data = del->next->data;
       del->next = del->next->next;
    }

};
