/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    stack<Node*> currlevel;
    stack<Node*> nextlevel;
    
    bool leftToRight = false;
    
    currlevel.push(root);
    while(!currlevel.empty()){
        Node* temp = currlevel.top();
        currlevel.pop();
        // if temp exists
        if(temp){
            ans.push_back(temp->data);
        }
        // if lefttoright is true push elements from left to right
        if(leftToRight){
            if(temp->left){
                nextlevel.push(temp->left);
            }
            if(temp->right){
                nextlevel.push(temp->right);
            }
        }
        // otherwise push elements from right to left
        else{
            if(temp->right){
                nextlevel.push(temp->right);
            }
            if(temp->left){
                nextlevel.push(temp->left);
            }
        }
        // if currlevel queue becomes empty
        if(currlevel.empty()){
            leftToRight = !leftToRight;
            swap(currlevel,nextlevel);
        }
        
    }
    
    // return the result
    return ans;
}
