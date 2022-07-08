/*
There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Find the predecessor and successor of the key in BST and sets pre and suc as predecessor and successor, respectively Otherwise, set to NULL.

Note: You don't need to print anything. You only need to set p.pre to the predecessor and s.succ to the successor. p and s have been passed in the function parameter.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1 */
// code
// Function to return the successor of the given key in the binary search tree
void succ(Node *root, int x, Node*& suc){
    Node *temp = root;
        // if temp exists
        while(temp != NULL) {
            // and the node's data is less than or equal to the root's data, go in the right direction
            if(temp->key <= x) {
               temp = temp->right;
            }
            // otherwise store the prev temp in the answer and go to the left node
            else {
                suc = temp;
                temp = temp->left;
            }
        }
}
// Function to return the predecessor of the given key in the binary search tree
void predec(Node *root, int x, Node*& pre)
    {
        //Your code here
        Node *temp = root;
        // if temp exists
        while(temp != NULL) {
            // and the node's data is greater than or equal to the root's data, go in the left direction
            if(temp->key >= x) {
                
               temp = temp->left;
            }
            // otherwise store the prev temp in the answer and go to the right node
            else {
                pre = temp;
                temp = temp->right;
            }
        }
        
    }
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    predec(root,key,pre);
    succ(root,key,suc);

}
