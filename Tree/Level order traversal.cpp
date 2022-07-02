/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2 */
// code

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      if(node == NULL){
          return ans;
      }
      // push root and null in queue
      queue<Node*> q;
      q.push(node);
      q.push(NULL);
      // take out element from the queue one by one and check for its left and right if exists
      while(!q.empty()){
          Node* node = q.front();
          q.pop();
          if(node!=NULL){
              ans.push_back(node->data);
              if(node->left){
                  q.push(node->left);
              }
              if(node->right){
                  q.push(node->right);
              }
          }
          else if(!q.empty()){
              q.push(NULL);
          } // pushing null back in the queue if queue is not empty
      }
      return ans;
    }
};
