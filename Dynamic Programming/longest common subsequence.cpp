class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int t[1001][1001]; //declaring a matrix to store the lcs
    int lcs(int x, int y, string s1, string s2)
    {   //initializing the first row and first column
        for(int i = 0; i<x+1; i++){
            for(int j = 0;j<y+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //filling other rows and columns of the matrix
        for(int i = 1; i<x+1; i++){
            for(int j = 1;j<y+1; j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[x][y];
    }
};
