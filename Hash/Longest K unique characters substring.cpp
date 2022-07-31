/* Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and 
returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1). */

//code
#include <iostream>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int mx = INT_MIN;
    unordered_map<char,int> mp;
    int i = 0, j = 0;
    while(j<s.size()){
        mp[s[j]]++;
        // if no. of unique characters is not equal to k
        if(mp.size()<k)j++;
        // if no. of unique characters is equal to k, store the size in mx
        else if(mp.size()==k){
            mx = max(mx,j-i+1);
            j++;
        }
        // if unique characters exceeds k, remove elements from the map until it's size remains greater than k
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                    
                }
                i++;
            }
            j++;;
        }
    }
    if(mx==INT_MIN) return -1;
    return mx;
    }
};

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.longestKSubstr(s,k)<<endl;
    }
	return 0;
}
