/* Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected 
after infinite units of time then simply return -1.

Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C) */

//code
class Solution {
public:
    //Function to check if the coordinates are valid or not, which means it should be inside the chess board
    bool isValid(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n = hospital.size();
        int m = hospital[0].size();
        
	    int uninfected = 0; // to count the no of uninfected patient
	   
	    int timeframe = 0;
	    
	    queue<pair<int,int>>q;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            // if it is a infected person
	            if(hospital[i][j] == 2)q.push({i,j});
	            else if(hospital[i][j] ==1)uninfected++;
	        }
	    }
	    if(uninfected==0) return 0;
	    
	    while(!q.empty()){
	        int size = q.size();
	        int temp = 0; // it will check if the current infected patient is affecting it's adjacent or not
	        
	        while(size!=0){
	            pair<int,int> p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	            // storing possible coordinates which can be infected by the infected patients
	            int ax[4] = {1, -1, 0, 0};
	            int ay[4] = {0, 0, 1, -1};
	            
	            for(int i = 0; i<4; i++){
	                
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                // if the next coordinate is within the grid and if its a uninfected patient
	                if(isValid(nx,ny,n,m,hospital)){
	                    temp++;
	                    hospital[nx][ny] = 2;
	                    q.push({nx,ny});
	                }
	            }
	            size--;
	        }
	        if(temp!=0) timeframe++;
	        // if any uninfected patient are still left, then return -1
	        
	    }
	    for(int i = 0; i<n; i++){
	            for(int j = 0; j<m; j++){
	               if(hospital[i][j] == 1){
	                   timeframe = 0;
	                   break;
	               }
	            }
	    }
	    return (timeframe == 0)? -1: timeframe;
    }
};
};
