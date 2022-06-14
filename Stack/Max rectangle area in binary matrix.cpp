/* Problem Link
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1 */

// code

class Solution{
  public:
  // Function to calculate the maximum area rectangle
    int MAH(vector<int> arr,int n){
     vector<int> nsel(n);
     vector<int> nser(n);
     stack<int> st;
     // For NSL
     for(int i=0;i<n;i++){
         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
         if(st.size()==0) nsel[i]=-1;
         else nsel[i]=st.top();
         // only push the index of the nsl in the stack
         st.push(i);
     }
     // make the stack empty to use it again
     while(!st.empty()) st.pop();
     // For NSR
     for(int i=n-1;i>=0;i--){
         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
         if(st.size()==0) nser[i]=n;
         else nser[i]=st.top();
         st.push(i);
     }
     int omax=0;
     for(int i=0;i<n;i++){
         int area=(nser[i]-nsel[i]-1)*arr[i];
         omax=max(omax,area);
     }
     return omax;
 }

    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>v;
        // store the first histogram vector as it is in v
        for(int j = 0; j<m; j++){
            v.push_back(M[0][j]);
            
        }
        int mx = MAH(v,m);
        // store other histograms in the vector one by one and calculate its maximum area
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(M[i][j] == 0){
                    v[j] = 0;
                }
                else{
                    v[j] = v[j] + M[i][j];
                }
                
            }
            mx = max(mx,MAH(v,m));
        }
        return mx;
    }
};
