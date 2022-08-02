/* Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 
Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n) */

//code

class Solution
{
    public:
    //Function to check if the coordinates are valid or not, which means it should be inside the chess board
    bool isValid(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
	    int fresh = 0; // to count the no of fresh oranges, for the case when we do not have any
	    // fresh orange
	    int timeframe = 0;
	    
	    queue<pair<int,int>>q;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            // if it is a rotten orange
	            if(grid[i][j] == 2)q.push({i,j});
	            else if(grid[i][j] ==1)fresh++;
	        }
	    }
	    if(fresh==0) return 0;
	    
	    while(!q.empty()){
	        int size = q.size();
	        int temp = 0; // it will check if the current rotten orange is affecting it's adjacent or not
	        
	        while(size!=0){
	            pair<int,int> p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	            // storing possible coordinates which can be rotten by the rotten oranges
	            int ax[4] = {1, -1, 0, 0};
	            int ay[4] = {0, 0, 1, -1};
	            
	            for(int i = 0; i<4; i++){
	                // coordinates of next step of knight
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                // if the next coordinate is within the grid and if its a fresh orange
	                if(isValid(nx,ny,n,m,grid)){
	                    temp++;
	                    grid[nx][ny] = 2;
	                    q.push({nx,ny});
	                }
	            }
	            size--;
	        }
	        if(temp!=0) timeframe++;
	        // if any fresh oranges are still left, then return -1
	        
	    }
	    for(int i = 0; i<n; i++){
	            for(int j = 0; j<m; j++){
	               if(grid[i][j] == 1){
	                   timeframe = 0;
	                   break;
	               }
	            }
	    }
	    return (timeframe == 0)? -1: timeframe;
    }
};
