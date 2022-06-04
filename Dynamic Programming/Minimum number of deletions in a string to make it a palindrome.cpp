#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
//calculating lcs of two string
int Lcs(string A, string B, int x, int y){
    for(int i = 0; i<x+1; i++){
            for(int j = 0;j<y+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //filling other rows and columns of the matrix
    for(int i = 1; i<x+1; i++){
        for(int j = 1;j<y+1; j++){
            if(A[i-1] == B[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[x][y];
}
//reversing string
string reverse(string str){
    int n = str.length();
    for(int i = 0; i<n/2;i++){
        swap(str[i],str[n-i-1]);
    }
    return str;
}
int minDeletions(string str, int n) { 
    string B = reverse(str);
    int m = B.length();
  //returning the result.
    return n - Lcs(str,B,n,m);
} 
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>m;
    string s;
    cin>>s;
    cout<<minDeletions(s,n)<<endl;
  }
  return 0;
}
