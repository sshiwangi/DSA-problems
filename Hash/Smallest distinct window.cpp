/* Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256) */

class Solution{    
public:
    int findSubString(string str)
    {
        //EX - "AABBBCBBAC"
        set<char> s;
        for(char c: str){
            s.insert(c);
        }
        //s = { A,B,C }
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int ans = str.size(); // if all the characters of the string are distinct
        // iterate in the string
        while(i<str.size()){
            mp[str[i]]++;
            // when the size of map becomes equal to the size of set
            // that is we found a possible substring containing all distinct char.
            if(mp.size() == n){
                // check if the char at j is greater than 1 in map,
                // if yes, decrease it's frequency and move j pointer
                while(mp[str[j]]>1){
                    mp[str[j]]--;
                    j++;
                }
                // after this while loop ends, the size of possible substring will
                // be i-j+1
                ans = min(ans,i-j+1);
            }
            i++;
        }
        return ans;
    }
};
