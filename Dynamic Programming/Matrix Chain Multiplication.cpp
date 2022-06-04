class Solution{
public:
int  t[101][101];
int solve(int arr[], int N, int i, int j){
    // i == j means 1 element and i>j means 0 element in array so no matrix possible in either case. so return 0
    if(i>=j){
        return 0;
    }
    // if any t[i][j] is not equal to -1 means it has come before in recursive call so just return the stored answer;
    if(t[i][j]!= -1){
        return t[i][j];
    }
    // declaring ans
    int ans = INT_MAX;
    // iterate over array and multiply every matrix possible.
    for(int k = i; k <= j-1; k++){
        ans = min(ans, (solve(arr,N,i,k) + solve(arr,N,k+1,j) + arr[i-1]*arr[k]*arr[j]));
    } 
    // return the minimum result.
    return t[i][j] = ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        // initializing matrix with -1
        memset(t, -1, sizeof(t));
        return solve(arr,N,1,N-1);
    }
};
