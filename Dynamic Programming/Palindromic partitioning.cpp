class Solution{
public:
//check for palindrome
bool isPalindrome(string str, int i, int j){
    if(i==j){
        return true;
    }
    if(i>j){
        return true;
    }
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
        
    }
    return true;
}
//declare a static matrix
    int t[501][501];
    int solve(string str, int i, int j){
        //i>=j means 1 and no element so in both the cases no partition required
        if(i>=j){
            return 0;
        }
        //if the string is already a palindrome, minm no of partition will be 0
        if(isPalindrome(str,i,j) == true){
            return 0;
        }
        // if ant t[i][j] != -1 that means it has been calculated and stored in the matrix so just return it.
        if(t[i][j]!=-1){
            return t[i][j];
            
        }
        // initialize answer to be a very large number
        int ans = INT_MAX;
        //iterate over the string and check for all partition possible
        for(int k = i; k<=j-1; k++){
            int left,right;
            
            if(t[i][k]!= -1){
                left = t[i][k];
            }
            else{
                left = solve(str,i,k);
            }
            t[i][k]=left;
            
            if(t[k+1][j]!= -1){
                right = t[k+1][j];
            }
            else{
                right = solve(str,k+1,j);
            }
            t[k+1][j] = right;
            int temp = 1 + left +right;
            //update the minimum answer
            ans = min(temp,ans);
        }
        //return the result
        return t[i][j] = ans;
    }
    
    int palindromicPartition(string str)
    {

        int n = str.length();
        //initializing the matrix with -1
        memset(t, -1, sizeof(t));
        return solve(str,0,n-1);
    }
};
