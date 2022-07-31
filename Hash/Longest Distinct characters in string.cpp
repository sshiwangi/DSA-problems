/* Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K), where K is Constant. */

//code
int longestSubstrDistinctChars (string S)
{
    // your code here
    int mx = INT_MIN;
    unordered_map<char,int> mp;
    int i = 0, j = 0;
    while(j<S.size()){
        mp[S[j]]++;
        
        if(mp[S[j]]==1){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(mp[S[j]] >1){
            while(mp[S[j]]>1){
                mp[S[i]]--;
                if(mp[S[j]]==0){
                    mp.erase(S[j]);
                }
                i++;
            }
            j++;
        }
    }
    return mx;
}
