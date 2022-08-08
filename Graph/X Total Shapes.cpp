/* Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).
 

Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.

Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.
 
Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 
Constraints:
1 ≤ n, m ≤ 100 */

//code
class Solution
{
    public:
    int n,m;
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 'O'){
            return;
        }
        grid[i][j] = 'O';
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        n = grid.size(); //no of rows
        m = grid[0].size(); // no of columns
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 'X'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
