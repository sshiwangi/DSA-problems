/* Given a string S and another string patt. Find the character in patt that is present at the minimum index in S.
 
Example 1:

Input: S = "zsyle", patt = "bjz"
Output: "z"

Expected Time Complexity: O(max(|str|, |patt|))
Expected Auxilary Space: O(K) where K <= 26 */

//code
class Solution
{
    public:
	string printMinIndexChar(string S, string patt)
	{
	    // Code here
	    int minIdx = INT_MAX;
    // store first occurence of each element in s
	    unordered_map<int,int> mp;
	    for(int i = 0; i<S.size(); i++){
	        if(mp.find(S[i])==mp.end()){
	            mp[S[i]] = i;
	        }
	        
	    }
	    // traverse in the patt array and store the minidx of char that is present in map
	    for(int i = 0; i<patt.size(); i++){
	        if(mp.find(patt[i])!=mp.end()){
	            minIdx = min(minIdx,mp[patt[i]]);
	        }
	    }
	    string ans = "";
	    if(minIdx == INT_MAX){
	        return "$";
	    }
	    else{
	        ans += S[minIdx];
	        return ans;
	    }
	   
	}
};
