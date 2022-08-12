/* Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 
Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.


Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of 
the largest region of 1's.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m) */

//code

class Solution
{
    public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid,int &area){
        // if the indices are out of boundary
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0)return;
        // mark it to be 0 so that we don't have to calculate the same area again
        grid[i][j] = 0;
        area++;
        // call for it's neighbours in all direction
        dfs(i,j+1,n,m,grid,area);
        dfs(i,j-1,n,m,grid,area);
        dfs(i-1,j,n,m,grid,area);
        dfs(i+1,j,n,m,grid,area);
        dfs(i+1,j+1,n,m,grid,area);
        dfs(i-1,j+1,n,m,grid,area);
        dfs(i+1,j-1,n,m,grid,area);
        dfs(i-1,j-1,n,m,grid,area);
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){ 
                    int area = 0;
                    dfs(i,j,n,m,grid,area);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};
