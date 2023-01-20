/* Problem link:https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?page=1&category[]=Dynamic%20Programming&sortBy=submissions
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, 
return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).


Constraints: 
1 ≤ |S| ≤ 103 */
//code
class Solution{
  public:
    string longestPalin (string S) {
       int n= S.length();
       vector<vector<int>>dp(n, vector<int>(n,0));
       string ans;
       int maxLen = 0;
       for(int diff = 0; diff<n; diff++){
           for(int i = 0, j = i+diff; j<n; i++,j++){
               if(i == j){ // if start and end index is same that is a single length string, then it will always be a palindrom
                   dp[i][j] = 1;
               }
               else if(diff == 1){ // if the length of the string is 2
                   dp[i][j] = (S[i] == S[j])?2:0;
               }
               else{
                   if((S[i] == S[j]) && dp[i+1][j-1]){ // if the outer index is same and the inner string is a palindrom
                       
                   
                     dp[i][j] = dp[i+1][j-1] + 2;
                   }
               }
               if(dp[i][j]){
                  if(j-i+1>maxLen){ // if the current length is greater than maxlen
                   maxLen = j-i+1;
                   ans = S.substr(i,maxLen);
                   }
                }
           }
       }
       
       return ans;
    }
};
