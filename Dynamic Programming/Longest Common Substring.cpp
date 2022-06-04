 class Solution {
   public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int t[n + 1][m + 1];
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){ // if the elements of bothe the string are equal
                    t[i][j] = 1 + t[i-1][j-1]; // store 1 and pass the rest into the function
                }
                else{
                    t[i][j] = 0; // otherwise store 0 in the matrix
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                mx=max(mx,t[i][j]);
            }
        }
        return mx;
    }
};
