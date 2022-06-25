/* Problem Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/?page=1&category[]=Queue&sortBy=submissions#
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k) */

// code
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        deque<int> q;
        
        int i;
        // For first k size window
        for(i = 0; i<k; i++){
            // if the element at the iterator i is greater than the element at the back of the deque
            // pop that out and push the new index
            while((!q.empty()) && arr[i] >= arr[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        // For the remaining windows
        for(i = k; i<n; i++){
            
            while((!q.empty()) && q.front() <= i-k){ // removing the index which does not belong to the window
                q.pop_front();
            }
            while((!q.empty()) && arr[i] >= arr[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};
