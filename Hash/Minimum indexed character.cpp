/* Given a string str and another string patt. Find the minimum index of the character in str that is also present in patt.

Example 1:

Input:
str = geeksforgeeks
patt = set
Output: 1
Explanation: e is the character which is
present in given str "geeksforgeeks"
and is also presen in patt "set". Minimum
index of e is 1. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters). */

// code
class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        unordered_map<char,int> mp;
        for(int i = 0; i<patt.length(); i++){
            mp[patt[i]]++;
        }
        
        for(int i = 0; i<str.length(); i++){
            // if we found the first common character, retur it's index
            if(mp.find(str[i])!=mp.end()){
                return i;
            }
        }
        return -1;
    }
};
