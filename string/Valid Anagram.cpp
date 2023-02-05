/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 
Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters. */

//code
class Solution {
public:
    bool isAnagram(string s, string t) {
        // for the string t to be anagram, it should have same characters as string s and also the count should be same too.
        vector<int>mp(26,0), mp1(26,0);
        for(int i = 0; i<s.size(); i++){
            mp[s[i]-'a']++;
        }
        for(int i = 0; i<t.size(); i++){
            mp1[t[i]-'a']++;
        }
        if(mp == mp1)return true;
        else return false;
    }
};
 
