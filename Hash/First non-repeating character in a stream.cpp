/* Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26) */

class Solution
{
  	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n = A.size();
		    // map will store frequency of the elements
		    unordered_map<char,int> mp;
		    // deque will maintain the order of elements
		    queue<int> q;
		    string ans = "";
		    
		    for(int i = 0; i<n; i++){
		        mp[A[i]]++;
		        // if element is not present in deque, insert it
		        if(mp[A[i]]<=1){
		            q.push(A[i]);
		        }
		        else{
		            //if the current character is repeated in stream
                    while(!q.empty() && mp[q.front()] != 1){
                        q.pop();// pop it
                    }
		        }
                
                // if dq becomes empty,append #
                if(q.empty()){
                    ans+='#';
                }
                // elese append front element
                else{
                    ans+=q.front();
                }
		    }
		    return ans;
		}

};
