/* Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed. */
// code

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy, *next = dummy, *pre = dummy;
        int count = 0;
      //counting the length of the linked list
        while(curr->next!=NULL){
            curr = curr -> next;
            count ++;
        }
         
        while(count>=k){
            curr = pre->next;
            next = curr ->next;
          // reversing the links in the groups of size k
            for(int i = 1; i<k; i++){
                curr->next = next->next;
                next->next = pre -> next;
                pre -> next = next;
                next = curr->next;
            }
            pre = curr;
            count-=k;
        }
        return dummy->next;
    }
};
