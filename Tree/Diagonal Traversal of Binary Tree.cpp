/* Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Here N is number of nodes. */

//code

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   queue<Node*> q;
   q.push(root);
   // take the elements out of queue and check if it's left exists or not,
   // if exists push it back in queue and move to its right and store the right's data in ans.
   // if the right becomes null, then start taking out the left node stored in the queue and 
   // follow the same method until queue becomes null
   
   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp){
           if(temp->left) q.push(temp->left);
           ans.push_back(temp->data);
           temp = temp->right;
       }// this while loop will break if the right becomes null
   }
   return ans;
   
}
