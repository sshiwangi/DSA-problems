/*
Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be printed in decreasing order.

Example 1:

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.

Expected Time Complexity: O(N + KlogK)
Expected Auxiliary Space: O(K+(N-K)*logK) */
// code

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    // store the elements in min heap so that the minimum elements stays at top
	    // and we can easily pop then whenever the size of heap becomes greater than k
	    priority_queue<int, vector<int>, greater<int>> minh;
	    for(int i = 0; i<n; i++){
	        minh.push(arr[i]);
	        if(minh.size()>k){
	            minh.pop();
	        }
	    }
	    // since we have to store the ans in decreasing order, take max heap that store max elements
	    // at top and we can take out the elements from top one by one and store in our result.
	    priority_queue<int> maxh;
	    vector<int> res;
	    while(minh.size()>0){
	        int ele = minh.top();
	        minh.pop();
	        maxh.push(ele);
	    }
	    while(maxh.size()>0){
	        res.push_back(maxh.top());
	        maxh.pop();
	    }
	    return res;
	}
