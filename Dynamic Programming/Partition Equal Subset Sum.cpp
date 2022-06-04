class Solution{
    
public:
    bool subsetSum(int arr[],int Sum,int N){
        int t[N+1][Sum+1];
        //initializing the matrix
        for(int i = 0; i<N+1; i++){
            for(int j = 0; j<Sum+1; j++){
                if(i==0){
                    t[i][j] = false;
                }
                if(j==0){
                    t[i][j] = true;
                }
            }
        }
        // fill the rest of the matrix
        for(int i = 1; i<N+1; i++){
            for(int j = 1; j<Sum+1; j++){
                if(arr[i-1]<=Sum){ // if the element is less than the required sum,
                    t[i][j] = (t[i-1][j-arr[i-1]]) || (t[i-1][j]); // we have two choices whether to take it or not
                }
                else{
                    t[i][j] = t[i-1][j]; // if the element is larger than the required sum, we'll not take it
                }
            }
        }
        return t[N][Sum]; 
    }

    int equalPartition(int N, int arr[])
    {
        //calculate the sum of array
        int sum = 0;
        for(int i = 0; i<N; i++){
            sum+=arr[i];
        }
        //if sum is odd, it's not possible to divide the array into two equal parts
        if(sum%2!=0){
            return false;
        }
        //if sum is even, check if there is a subset having sum equal to half the sum of array
        else{
            return subsetSum(arr,(sum/2),N);
        }
    }
};
