/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	if(root == NULL){
    	    return ans;
    	}
    	queue<Node*> q;
    
    	bool leftToRight = true;
    	q.push(root);
    	
    	while(!q.empty()){
    	    // take out all elements at a particular level and push it in row vector in the correct position
    	    int size = q.size();
    	    vector<int> row(size);
    	    for(int i = 0; i<row.size(); i++){
    	        Node* temp = q.front();
    	        q.pop();
    	        // finding position in the row vector to fill node's value
    	        // if the lefttoright is true, we will push the node's vaue from rear end
    	        // else we will push it from front.
    	        
    	        int index = (leftToRight)? i: (size-1-i);
    	        row[index] = temp->data;
    	        
    	        if(temp->left) q.push(temp->left);
    	        if(temp->right) q.push(temp->right);
    	    }
    	    // traverse in the row and store the elements in the ans vector
    	    for(int i=0; i<row.size(); i++){
    	        ans.push_back(row[i]);
    	    }
    	    // change the value of left to right
    	    leftToRight = !leftToRight;
    	}
    	return ans;
    }
};
