/* Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256) */

//code
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char, int> mp;
	    for(int i = 0; i<pat.size(); i++){
	        mp[pat[i]]++;
	    }
	    int count = mp.size();
	    int ans = 0;
	    
	    int i = 0, j = 0;
	    while(j<txt.size()){
	       // do the calculation
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            
	            if(mp[txt[j]] == 0){
	                count--;
	            }
	        }
	        if((j-i+1) < pat.size()){
	            j++;
	        }
	        else if((j-i+1) == pat.size()){
	            // find ans from calculation
	            if(count == 0){ // we found one anagram
	                ans++;
	            }
	            // slide the window but before that make sure to remove all the calculation related
	            // to the i if txt[i] is present in map
	            if(mp.find(txt[i])!=mp.end()){
	                mp[txt[i]]++;
	                if(mp[txt[i]] ==1){
	                    count++;
	                }
	            }
	            i++;
	            j++;
	        }
	        
	    }
	    return ans;
	}

};
