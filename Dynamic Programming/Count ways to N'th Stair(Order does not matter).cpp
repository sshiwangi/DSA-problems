class Solution {
  public:
	//similar to coin change problem
	int solve(int arr[],int n){
	    int dp[3][n+1];
	    
	    for(int i = 0; i<3; i++){
	        for(int j = 0; j<n+1; j++){
	            if(i == 0){
	                dp[i][j] = 0;
	            }
	            if(j == 0){
	                dp[i][j] = 1;
	            }
	        }
	    }
	    for(int i = 1; i<3; i++){
	        for(int j = 1; j<n+1; j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    return dp[2][n];
	}
		int nthStair(int n){
		    //  Code here
		    int stairs[2];
		    for(int i = 0; i<2; i++){
		        stairs[i] = i +1;
		    }
		    return solve(stairs,n);
		}
};
