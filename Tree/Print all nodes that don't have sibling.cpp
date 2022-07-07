/*
Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order.

Note: Root node can not have a sibling so it cannot be included in our answer.

Example 1:

Input :
       37
      /   
    20
    /     
  113 

Output: 20 113
Explanation: 20 and 113 dont have any siblings.


Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(Height of the tree) */

// code
vector<int> noSibling(Node* node)
{
    // we will carry a queue and an answer vector
    vector<int> ans;
    queue<Node*> q;
    // first we push the root node in the queue
    q.push(node);
    while(!q.empty()){
        // then take out the node from the queue and check if only one of the left or right
        // node exist then it has no sibling so insert the node's left or right whichever exist
        // in the answer vector
        Node* temp = q.front();
        q.pop();
        // If there is no sibling
        if(temp->left!= NULL && temp->right == NULL){
            ans.push_back(temp->left->data);
        }
        if(temp->right!= NULL && temp->left == NULL){
            ans.push_back(temp->right->data);
        }
        // after that we will push the left and right in the queue if exists
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    // sorting the answer in ascending order
    sort(ans.begin(),ans.end());
    // if there is no element which don't have siblings then return -1;
    if(ans.size() == 0) ans.push_back(-1);
    return ans;
    
    
    
}
