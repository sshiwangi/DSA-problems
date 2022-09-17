/* Given two arrays A and B contains integers of size N and M, the task is to find numbers which are present in the first array, but not present in the second array.

Example 1:

Input: N = 6, M = 5
A[] = {1, 2, 3, 4, 5, 10}
B[] = {2, 3, 1, 0, 5}
Output: 4 10
Explanation: 4 and 10 are present in 
first array, but not in second array.
Example 2:

Input: N = 5, M = 5
A[] = {4, 3, 5, 9, 11}
B[] = {4, 9, 3, 11, 10}
Output: 5  
Explanation: Second array does not 
contain element 5.

Expected Time Complexity: O(N+M).
Expected Auxiliary Space: O(M). */

//code
class Solution{
	public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    // Your code goes here
	    vector<long long> ans;
	    unordered_map<long long,long long> mp;
	    for(int i = 0; i<M; i++){
	        mp[B[i]]++;
	    }
	    for(int i = 0; i<N; i++){
	        if(mp.find(A[i])==mp.end()){
	            ans.push_back(A[i]);
	            
	        }
	    }
	    return ans;
	    
	} 
};
