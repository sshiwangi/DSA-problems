class Solution {
  public:
    int editDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i<=m; i++){
          for(int j = 0; j<=n; j++){
              // i == 0 means string 1 is eshausted that is empty, so inorder to convert it into
              //string 2, we just need to insert characters = no of elements present in string 2
              if(i == 0){
                  dp[0][j] = j;
              }
            // j == 0 means string 2 is eshausted that is empty, so inorder to convert str1 into
              //string 2, we just need to delete remaining characters from str1
              if(j == 0){
                  dp[i][0] = i;
              }
           }
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                // if the last characters are matching, check for remaining ones
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                //else we must require 1 of any three operations. so add 1 and take minimum of insertion,deletion,and repacement
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
        
    }
};
