/* Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S| */

// code
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       //same as first non repeating char in a stream
       unordered_map<char,int> mp;
       queue<char> q;
       for(int i = 0; i<S.size(); i++){
           mp[S[i]]++;
           
           if(mp[S[i]]<=1){
               q.push(S[i]);
           }
           else{
               while(!q.empty() && mp[q.front()]!=1){
                   q.pop();
               }
           }
       }
       if(q.empty()) return '$';
       else return q.front();
       
    }

};
