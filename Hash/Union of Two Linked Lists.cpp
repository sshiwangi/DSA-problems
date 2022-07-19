/* Given two linked lists, your task is to complete the function makeUnion(), that returns the union of two linked lists. This union should include all the distinct elements only.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 1 2 3 4 6 8 9
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Note: The new list formed should be in non-decreasing order.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(N) */
//code

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    unordered_map<int,int> mp;
    Node* temp1 = head1;
    Node* temp2 = head2;
    // storing the unique elements of both the linked list in map
    while(temp1!=NULL){
        mp[temp1->data]++;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        mp[temp2->data]++;
        temp2 = temp2->next;
    }
    // store the unique elements in vector
    vector<int> v;
    for(auto it: mp){
        v.push_back(it.first);
    }
    // sorting the vector
    sort(v.begin(),v.end());
    Node* newNode = new Node(-1);
    Node* ans = newNode;
    // iterate in the vector and add each node to next of new head;
    for(int i = 0; i<v.size(); i++){
        ans->next = new Node(v[i]);
        ans = ans->next;
    }
    // return the ans
    return newNode->next;
}
