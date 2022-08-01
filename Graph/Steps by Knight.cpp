/* Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).*/

//code

class Solution
{
    public:
    //Function to check if the coordinates are valid or not, which means it should be inside the chess board
    bool isValid(int i, int j, int n, vector<vector<bool>>&visited){
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j] == false){
            return true;
        }
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int kx = KnightPos[0]-1, ky = KnightPos[1]-1;
	    
	    // if knight and target position are same
	    if(kx == tx && ky == ty)return 0;
	    
	    vector<vector<bool>>visited(n, vector<bool>(n, false));
	    
	    queue<pair<int,int>>q;
	    q.push({kx, ky}); //push the knight's initial position
	    
	    visited[kx][ky] = true;
	    
	    int ans = 0; // stores the minimum step
	    
	    while(!q.empty()){
	        int size = q.size();
	        ans++;
	        
	        while(size!=0){
	            pair<int,int> p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	            // storing possible coordinates where the knight can go
	            int ax[8] = {1,1,-1,-1,2,-2,2,-2};
	            int ay[8] = {2,-2,2,-2, 1,1,-1,-1};
	            
	            for(int i = 0; i<8; i++){
	                // coordinates of next step of knight
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx && ny == ty) return ans;
	                
	                // if it's not equal to target position then check if it's valid or not,
	                if(isValid(nx,ny,n,visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx,ny});
	                }
	            }
	            size--;
	        }
	    }
	    return ans;
	}
};

 

 
