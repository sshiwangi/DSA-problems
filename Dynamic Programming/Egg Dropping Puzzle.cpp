class Solution{
public:
    //declare the matrix
    int t[201][201];
    int solve(int e, int f){
        //if floor = 0 or floor = 1 , no of attempts will be equal to floor number.
        if(f==0 || f==1){
            return f;
        }
        // if egg = 1, in worst case the critical floor will be at the top of the building that is equal to the no of floors
        if(e == 1){
            return f;
        }
        // if t[e][f] is solved earlier, return the value
        if(t[e][f]!=-1){
            return t[e][f];
        }
        // create an answer variable for storing the minm attempts
        int ans = INT_MAX;
        for(int k = 1; k<=f; k++){
            int low, high;
            if(t[e-1][k-1]!=-1){
                low = t[e-1][k-1];
            }
            else{
                low = solve(e-1,k-1);
                t[e-1][k-1] = low;
            }
            if(t[e][f-k]!=-1){
                high = t[e][f-k];
            }
            else{
                high = solve(e,f-k);
                t[e][f-k] = high;
            }
            // max(of low, high) is for worst case
            int temp = 1 + max(low, high);
            ans = min(ans,temp);
        }
        return t[e][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};
