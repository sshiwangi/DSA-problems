/* Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3
M=4
A=[[1,0,0,0], 
[1,1,0,1],[0,1,1,1]]
X=2
Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.


Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

 

Constraints:
1 <= N,M <= 250

0 <= X < N

0 <= Y < M
0 <= A[i][j] <= 1 */

//code
class Solution {
  public:
  // DFS traversal will give tle
  
    int da[4] = {1, -1, 0, 0};
    int db[4] = {0, 0, 1, -1};
    bool isValid(int i, int j, int n, int m, vector<vector<int>>&A){
        if(i>=0 && i<n && j>=0 && j<m && A[i][j] == 1){
            return true;
        }
        return false;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       
        vector<vector<int>>vis(N,vector<int>(M,0));
        vector<vector<int>>dis(N,vector<int>(M,INT_MAX));
        queue<pair<int,int>> q;
        if(A[0][0] == 0) return -1;
        
        q.push({0,0});
        
        vis[0][0]=1;
        dis[0][0]=0; // distance of source from the source is 0
         
        while(!q.empty()){
            auto top = q.front();
            int a = top.first;
            int b = top.second;
            q.pop();
            
            
            for(int i = 0; i<4; i++){
                int na = a + da[i];
                int nb = b + db[i];
                
                if(isValid(na,nb,N,M,A) && !vis[na][nb]){
                    if(na == X && nb == Y){ // if the next adj is the destination
                        // if distance of next indices from the source is less, store it in distance array
                        if(dis[na][nb] > 1 + dis[a][b]){
                            dis[na][nb] = 1 + dis[a][b];
                        }
                    }
                    // if the next adj is not the destination, but is valid so move in that direction and store new index if it is lesser than the already existing one
                    
                    if(dis[na][nb] > 1 + dis[a][b]){
                        dis[na][nb] = 1 + dis[a][b];
                    }
                    vis[na][nb] = 1;
                    q.push({na, nb});
                    
                }
            }
        }
        // if found a shortest distance
        if(dis[X][Y]!=INT_MAX){
            return dis[X][Y];
        }
        return -1; // if not found the shortest distance
        
    }
};
