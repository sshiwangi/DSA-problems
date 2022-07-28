/* Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)
*/
//code
class Solution{
public:
    void checkIslands(vector<vector<char>>& grid, int i, int j){
        // if the recursive call goes out of bound
        if(i<0 || j <0 || i>= grid.size()|| j>=grid[0].size() || grid[i][j] != '1'){
            return;
        }
        
        grid[i][j] = '0'; // mark it to be 0 then call for it's adjacent
        checkIslands(grid,i+1,j);
        checkIslands(grid,i-1,j);
        checkIslands(grid,i,j+1);
        checkIslands(grid,i,j-1);
        // for diagonals
        checkIslands(grid,i+1,j+1);
        checkIslands(grid,i+1,j-1);
        checkIslands(grid,i-1,j-1);
        checkIslands(grid,i-1,j+1);
        return;
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        for(int i = 0; i<grid.size(); i++){ //across rows
            for(int j = 0; j<grid[0].size(); j++){ //across columns
                if(grid[i][j] == '1'){
                    checkIslands(grid,i,j);
                    count++;
                }
                
            }
        }
        return count;
    }
};
