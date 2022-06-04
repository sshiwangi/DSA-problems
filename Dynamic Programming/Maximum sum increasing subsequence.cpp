class Solution {
  public:
	int solve(int arr[], int n, int ind, int prev_ind, vector<vector<int>> &dp){
	    // if the current index becomes n then return 0 because we came out of the array
	    if(ind == n){
	        return 0;
	    }

	    if(dp[ind][prev_ind + 1] != -1){
	        return dp[ind][prev_ind + 1];
	    }
	    int maxSum = solve(arr,n,ind+1,prev_ind,dp); // when we do not take the element
	    if(prev_ind == -1 || arr[ind]>arr[prev_ind]){ // when we take the element
	        maxSum = max(maxSum, arr[ind] + solve(arr,n,ind+1,ind,dp)); // ans will be maximum of don't take and take choices
	      
	    }
	  
	    return dp[ind][prev_ind+1] = maxSum;
	    
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    // initializing dp with -1
	    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	    return solve(arr,n,0,-1,dp);
	}  
};
