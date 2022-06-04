class Solution {
  public:
  int solve(Node* root, int& res){
      //base condn
      if(root == NULL){
          return 0;
      }
      int leftAns = solve(root->left, res);
      int rightAns = solve(root->right, res);
      // if the longest path does not go through the current node, then it will store the value in temp and pass it to next node
      int temp = 1 + max(leftAns, rightAns); 
      // the ans variable store the maximum of temp ans and the answer through the node
      int ans = max(temp, 1+leftAns+rightAns);
      res = max(res,ans);
      return temp; // the value inside temp will be used by other recursive calls
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
