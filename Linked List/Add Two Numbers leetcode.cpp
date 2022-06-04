/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807. */

// code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *head = ans; // pointer pointing at head of the answer node

        int carry = 0;
        // if l1 and l2 are not null
        while (l1 && l2)
        { // store the sum of the values of the nodes in the sum variable
            int sum = (l1->val + l2->val + carry); 
            // make a new node having the last digit of the sum as the value of the node
            ListNode *temp = new ListNode(sum % 10); 
            // make update carry
            // it stores the first digit of sum
            carry = sum / 10;
            // store the new node temp in the next of head pointer
            head->next = temp;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // if the linked list 1 is not null but list 2 is null
        while (l1)
        {
            int sum = l1->val + carry;
            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;
            head->next = temp;
            head = head->next;
            l1 = l1->next;
        }
        // if the linked list 2 is not null but list 1 is null
        while (l2)
        {
            int sum = l2->val + carry;
            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;
            head->next = temp;
            head = head->next;
            l2 = l2->next;
        }
        // if carry is greater than 0
        if (carry)
        {
            int sum = carry;
            ListNode *temp = new ListNode(sum % 10);
            head->next = temp;
        }
        return ans->next;
    }
};
