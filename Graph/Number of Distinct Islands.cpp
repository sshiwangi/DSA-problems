/* Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms 
an island. Two islands are considered to be identical if and only if one island is equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
Island 1, 1 at the top left corner is same as island
1, 1 at the bottom right corner.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total 
number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m) */

//code
// we will represent the islands in the form of strings and insert it in a set. so when we encounter
// identical islands, it will not get inserted in the set and we will only have distinct islands and
// we can return the size of set.

/* the strings will have these characters in it
 X = start of island
 O = out of bound or water
 U = up recursive call
 L = left recursive call
 R = right recursive call
 D = down recursive call
*/
class Solution {
    private: 
    string dfs(int i, int j, int n, int m, vector<vector<int>>& grid, string direction){
        if(i<0 || j<0 || i>=n || j>= m || grid[i][j] == 0){
            return "0";
        }
        grid[i][j] = 0;
        
        string left = dfs(i,j-1,n,m,grid,"L");
        string right = dfs(i,j+1,n,m,grid,"R");
        string up = dfs(i-1,j,n,m,grid,"U");
        string down = dfs(i+1,j,n,m,grid,"D");
        
        return direction + left + right + up + down;
    }
  public:
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<string> ans;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    string temp = dfs(i,j,n,m,grid,"X");
                    ans.insert(temp);
                }
            }
        }
        return ans.size();
    }
};
