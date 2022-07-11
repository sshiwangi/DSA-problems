/*
Given an input stream arr[] of n integers. Find the Kth largest element for each element in the stream and if the Kth element doesn't exist, return -1.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.

Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n) */

// code
class Solution
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> ans;
        // take a min heap as we need kth largest element
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i = 0; i<n; i++){
            // push elements one by one
            minh.push(arr[i]);
            if(minh.size()<k){ // check if the kth largest num exists or not
                ans.push_back(-1);
            }
            // when the size of minh is equals to k, print the top element
            else if(minh.size() == k){ 
                ans.push_back(minh.top());
                
            }
            // else, pop the first element and then push the top element in the ans
            else{
                minh.pop();
                ans.push_back(minh.top());
            }
        }
        return ans;
    }
};
