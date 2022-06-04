class Solution {	
public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Top Down Approach
	    // Declaring a matrix to store the values
	    int t[M+1][V+1];
	    for(int i = 0; i<M+1; i++){
	        for(int j = 0; j<V+1; j++){
	            if(i==0){ // if coin array is empty that is its size is 0 then initialize it with INT_MAX -1 for avoiding integer overflow
	                t[i][j] = INT_MAX -1;
	            }
	            else if(i==1){ // initializing first row
	                if(j%coins[0]==0){
	                    t[i][j] = j/coins[0];
	                }
	                else{
	                    t[i][j] = INT_MAX -1;
	                }
	            } // initializing first column
	            else if(j==0){
	                t[i][j] = 0;
	            }
	        }
	    }
	    // initializing from 2nd row onwards
	    for(int i = 2; i<M+1; i++){
	        for(int j = 1; j<V+1; j++){
	            if(coins[i-1]<=j){
	                t[i][j] = min(t[i][j-coins[i-1]] +1,t[i-1][j]);
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    if(t[M][V] == INT_MAX-1){
	        return -1;
	    }
	    return t[M][V];
	} 
	  
};
