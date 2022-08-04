/* Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
 

Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0 
3 0 0 0 3 
3 3 3 3 3 
0 2 3 0 0 
3 0 0 1 3 
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)
*/
//code
class Solution
{
    public:
    // Function to find if the position is valid or not
    bool isValid(int i, int j, int n){
        if(i>=0 && i<n && j>=0 && j<n){
            return true;
        }
        return false;
    }
    //Function to find whether a path exists from the source to destination
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        queue<pair<int,int>>q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    // since it is given that there is only 1 source, break out of the loop to optimize it
                    break;
                }
            }
        }
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
                
            int x = ele.first;
            int y = ele.second;
            
            int dx[] = {-1,0,1,0};
            int dy[] = {0,-1,0,1};
                
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                    
                if(isValid(nx,ny,n)){
                    if(grid[nx][ny] ==2){ // if the position is our destination
                        return true;
                    }
                    if(grid[nx][ny] == 3){ // if it is a blank space,we might get the destination through this coordinate,so push it in queue.
                        grid[nx][ny] = true;
                         q.push({nx,ny});
                    }
                }
            }
                
        }
        return false;
    }
};
