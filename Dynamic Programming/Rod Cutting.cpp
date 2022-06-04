class Solution{
  public:
  // Top Down approach
    int t[1001][1001]; // Declare a matrix to store the values
    int maxProfit(int len[],int price[], int n){
        // initialize first row and column
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<n+1; j++){
                // store 0 in the matrix if the array is empty or the length of the array is 0
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<n+1; j++){
                if(len[i-1]<=j){ //if length of the item is less than or equal to the length of the rod
                // we'll have two choices whether to take the item or leave it
                    t[i][j] = max((price[i-1]+t[i][j-len[i-1]]),t[i-1][j]); // take the maximum of both the possibilities
                }
                else{
                    // else do not take the item
                    t[i][j] = t[i-1][j];
                }
            }
        }
        // return the answer
        return t[n][n];
    }
    int cutRod(int price[], int n) {
        int len[n];//declare a length array
        for(int i = 0; i<n; i++){ // store the values up to n in the array
            len[i] = i +1;
        }
        return maxProfit(len,price,n);
    }
};
