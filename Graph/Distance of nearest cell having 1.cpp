/* Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column 
number of the nearest cell having value 1.

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m) */

//code
class Solution
{
    public:
    bool isValid(int i, int j,int n, int m, vector<vector<int>>&grid){
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(); // rows
	    int m = grid[0].size(); // column
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(n, vector<int>(m,INT_MAX-1));
	    
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            // if its a 1, then it is itself the nearest one, so put 0 in it's place
	            if(grid[i][j] == 1){ 
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        auto top = q.front();
	        int i = top.first;
	        int j = top.second;
	        q.pop();
	        
	        // find its adjacent in all directioon
	                
	        int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,1,-1};
                    
	        for(int k = 0; k<4; k++){
	            
	            int nx = i + dx[k];
	            int ny = j + dy[k];
	           // if the adjacent is valid
	            if(isValid(nx,ny,n,m,grid)){
	                if(ans[nx][ny] > ans[i][j] + 1){
	                       
	                   ans[nx][ny] = ans[i][j] + 1;
	                   q.push({nx,ny});
	                }
	            }
	        }
	    }
	    return ans;
	    
	}
};
