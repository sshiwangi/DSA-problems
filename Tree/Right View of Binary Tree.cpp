/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8
     */
     
// code

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
   if(root == NULL){
       return ans;
   }
   // We will traverse the node level wise
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();
       for(int i = 0; i<n; i++){
           Node* temp = q.front();
           q.pop();
           // if the node is the last element that is the right most element, we will store that in ans.
           if(i==n-1){
               ans.push_back(temp->data);
           }
           if(temp->left!=NULL){
               q.push(temp->left);
           }
           if(temp->right!=NULL){
               q.push(temp->right);
           }
       }
   }
   return ans;
    }
};
