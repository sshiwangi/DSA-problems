#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  // finding Lcs of two string
  int t[1001][1001];
  int Lcs(string A, string B, int m, int n){
      for(int i = 0; i<m+1; i++){
            for(int j = 0;j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //filling other rows and columns of the matrix
        for(int i = 1; i<m+1; i++){
            for(int j = 1;j<n+1; j++){
                if(A[i-1] == B[j-1]){
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
  }
  //reversing the string A
  string reverseString(string A, int m){
      for (int i = 0; i < m / 2; i++){
            swap(A[i], A[m - i - 1]);
        }
        return A;
  }
  
    int longestPalinSubseq(string A) {
        //code here
        
        int m = A.length();
        string B = reverseString(A,m);
        int n = B.length();
        return Lcs(A,B,m,n);
    }
};
int main(){
  int t; cin>>t;
  while(t--){
    string s; cin>>s;
    Solution ob;
    cout <<ob.longestPalinSubseq(s)<<endl;
