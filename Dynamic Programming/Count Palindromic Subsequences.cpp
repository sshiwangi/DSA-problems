class Solution {
public:
    int t[1001][1001];
    long long num = 1e9 + 7;
    long long int solve(string &str, int i, int j){
        //i>j means no string so no palindromic subsequence
        if(i>j){
            return 0;
        }
        // i == j means length of string is 1 so return 1
        if(i==j){
            return 1;
        }
        
        // if ant t[i][j] != -1 that means it has been calculated and stored in the matrix so just return it.
        if(t[i][j]!=-1){
            return t[i][j];
            
        }
        // if the first and last element of the string is equal
        if(str[i] == str[j]){
            return t[i][j] = (1 + solve(str,i+1,j) +solve(str,i,j-1))%num;
        }
        //if not same
        else{
            return t[i][j] = (num + solve(str,i+1,j) + solve(str,i,j-1) - solve(str,i+1,j-1))%num;
        }
}
    
    long long int  countPS(string str)
    {
      //Your code here
      memset(t, -1, sizeof(t));
      return solve(str,0,str.size()-1);
    }
     
}; 
