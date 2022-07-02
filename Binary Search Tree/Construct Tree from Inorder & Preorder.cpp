/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 
Example 1:
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).*/

// code

class Solution{
    public:
    Node* makeBT(int pre[],int ps,int pe,int in[],int is,int ie,map<int,int> &mp){
        if(ps>pe || is>ie)return NULL;
        Node* root=new Node(pre[ps]); // the first element of the pre array will be our root
        int inRoot = mp[root->data]; // finding the root element in the inorder array
        int numLeft=inRoot-inStart; // finding no of elements in the left subtree
        root->left=makeBT(pre,ps+1,ps+numsLeft,in,is,inRoot-1,mp);
        root->right=makeBT(pre,ps+numsLeft+1,pe,in,inRoot+1,ie,mpp);
        return root;
    
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // we will store the inorder elements in map along with their index
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        return makeBT(pre,0,n-1,in,0,n-1,mp);
    }
};
