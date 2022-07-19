/* Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n) */

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        Node* newhead = new Node(-1);
        Node* ans = newhead;
        
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        unordered_map<int,int> mp;
        // storing the nodes of 2nd linked list in map
        while(temp2!=NULL){
            mp[temp2->data]++;
            temp2 = temp2->next;
        }
        // iterate in first linked list
        while(temp1!=NULL){
            // if the node of l1 is present in mp, we found the common node
            if(mp.find(temp1->data)!=mp.end()){
                ans->next = new Node(temp1->data);// put in the next of ans
                mp[temp1->data]--; // decrease it's frequency
                if(mp[temp1->data]==0){ // it it's value becomes 0, erase it from map
                    mp.erase(temp1->data);
                }
                temp1 = temp1->next; // and move temp1 pointer
                ans = ans->next; // and ans pointer
            }
            // other wise move temp1 pointer
            else{
                temp1 = temp1->next;
            }
        }
        // return new head
        return newhead->next;
    }
};
