class Solution{
public:
int t[1001][1001];
    int knapSack(int N, int W, int val[], int wt[])
    {
        // initializing first row and first column
        for(int i = 0; i<N+1; i++){
            for(int j = 0; j<W+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //Filling other rows and columns
        for(int i = 1; i<N+1; i++){
            for(int j = 1; j<W+1; j++){
                //if weight of the item is less than given weight limit
                if(wt[i-1]<=j){
                    // we will have two choices whether to take it or leave it
                    // take the maximum of both the possibilities
                    t[i][j] = max((val[i-1] + t[i][j-wt[i-1]]),t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        //return the answer
        return t[N][W];
    }
};
