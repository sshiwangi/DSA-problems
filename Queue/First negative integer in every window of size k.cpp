/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K) */

// code
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        
        deque<long long int> q;
        vector<long long> ans;
        // Processing the first window of size k
        for(int i = 0; i<K; i++){
            if(A[i]<0){
                q.push_back(i);
            }
        }
        // storing the answer
        
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(A[q.front()]);
        }
        
        // Processing the remaining windows
        
        for(int i = K; i<N; i++){
            // Removal
            if(!q.empty() && i-q.front() >= K){
                q.pop_front();
            }
            // addition of new element
            if(A[i]<0){
                q.push_back(i);
            }
            
            // storing the answer
            if(q.empty()){
               ans.push_back(0);
            }
            else{
               ans.push_back(A[q.front()]);
            }
        }
        return ans;
 }
