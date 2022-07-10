/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =  {{16, 28, 60, 64},
            {22, 41, 63, 91},
            {27, 50, 87, 93},
            {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.

Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N) */

// code
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //traverse in the matrix and push the elements in the maxheap, it will sort it and return the top element of the heap
  priority_queue<int> maxh;
  for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
          maxh.push(mat[i][j]);
          if(maxh.size()>k){
              maxh.pop();
          }
      }
  }
  return maxh.top();
}
