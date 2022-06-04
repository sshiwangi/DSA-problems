class Solution {
public:
  long long int t[1001][1001];
    long long int count(int S[], int m, int n) {
        //Initializing first row and first column of the matrix
        for(int i = 0; i<m+1; i++){
            for(int j = 0; j<n+1; j++){
                // if the array is empty there will be 0 no. of ways to make change for n cents
                if(i==0){
                    t[i][j] = false;
                }
                //if n = 0 then there will always be 1 set that is empty set fulfilling the criteria
                if(j==0){
                    t[i][j] = true;
                }
            }
        }
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                // if the element is less than the given value n
                if(S[i-1]<=j){
                    // there will be two possibilities whether to take it or leave it
                    t[i][j] = t[i][j-S[i-1]] + t[i-1][j]; // here they are asking about total no. of ways so add both the possibilities
                }
                else{
    
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[m][n];
    }
};
