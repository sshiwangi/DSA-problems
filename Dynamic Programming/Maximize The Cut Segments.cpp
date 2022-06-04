class Solution
{
    public:
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int t[4][n+1];
        int cuts[3];
        cuts[0] = x;
        cuts[1] = y;
        cuts[2] = z;
        
        for(int i = 0; i<4; i++){
            for(int j = 0; j<n+1; j++){
                if(i==0){
                    t[i][j] = INT_MIN;
                }
                if(j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int  i = 1; i<4; i++){
            for(int j = 1; j<n+1; j++){
                
                if(cuts[i-1]<=j){
                    
                    
                    t[i][j] = max(1 + t[i][j-cuts[i-1]],t[i-1][j]);
                    
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
         if(t[3][n]<0)
      {
          return 0;
      }
        return t[3][n];
    }
    
};
