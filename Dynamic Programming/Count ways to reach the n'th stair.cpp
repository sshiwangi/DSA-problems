class Solution {
  public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int num = 1e9 + 7;
        int dp[n+2];
        dp[1] = 1; // if n = 1 then there is only one possible way
        dp[2] = 2; // if n = 2 then there are two possible ways to reach 2nd stair, either 1 step each time or 2 steps at once
        for(int i = 3; i < n+1; ++i)
            dp[i] = dp[i-1]%num + dp[i-2]%num;
        return dp[n]%num;
    }
};
