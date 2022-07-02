/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
     
Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N) */

//code
int postIndex;
int search(int in[], int start, int end, int val){
    for(int i = start; i<=end; i++){
        if(in[i] == val){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[], int post[], int st, int end){
    if(st>end){
        return NULL;
    }
    int val = post[postIndex];
    postIndex--;
    Node* curr = new Node(val);
    if(st == end){
        return curr;
    }
    int inIndex = search(in,st,end,val);
    curr->right = solve(in,post,inIndex+1,end);
    curr->left = solve(in,post,st,inIndex-1);
    return curr;
    
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    postIndex = n-1;
    return solve(in,post,0,n-1);
}
