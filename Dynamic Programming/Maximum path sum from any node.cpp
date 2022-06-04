class Solution {
  public:
  int solve(Node* root, int& res){
      if(root == NULL){
          return 0;
      }
      int left = solve(root->left, res);
      int right = solve(root->right, res);
      // if the maximum path does not passes through the node,
      //and its subtrees gives positive value, then calculate the maximum of its left subtree and right subtree and add its value
      // but if the subtrees returns the negative value then only return the value of the root
      // after that store its maximum in the variable called temp.
      int temp = max((max(left,right)+root->data), root-> data);
      int ans = max(temp,left+right+root->data);
      res = max(res,ans);
      return temp;
  }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
