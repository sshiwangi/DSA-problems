/* Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's given preorder traversal. 
In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Example 1:

Input:

N = 5
arr[]  = {40,30,35,80,100}

Output: 35 30 100 80 40

Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:

              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40

Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

//code
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution{
public:
    Node* makeBT(int pre[],int ps,int pe,int in[],int is,int ie,map<int,int> &mp){
        if(ps>pe || is>ie)return NULL;
        Node* root= newNode(pre[ps]); // the first element of the pre array will be our root
        int inRoot = mp[root->data]; // finding the root element in the inorder array
        int numLeft=inRoot-is; // finding no of elements in the left subtree
        root->left=makeBT(pre,ps+1,ps+numLeft,in,is,inRoot-1,mp);
        root->right=makeBT(pre,ps+numLeft+1,pe,in,inRoot+1,ie,mp);
        return root;
    
    }
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        //code here
        int in[size];
        for(int i = 0; i<size; i++){
            in[i] = pre[i];
        }
        sort(in, in+size);
        map<int,int> mp;
        for(int i=0;i<size;i++){
            mp[in[i]]=i;
        }
        return makeBT(pre,0,size-1,in,0,size-1,mp);
    }
};
