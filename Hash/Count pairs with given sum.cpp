/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */

// code
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // we basically need pair of elements such that their sum becomes equal to k
        // i.e x1 + x2 = k
        // we only want to traverse the array once, so let's say each time x1 will be elemennts
        // of array so traverse the array and each time find x2 by calculating k - x1. and check
        // if the x2 we need is even present in the map or not. if present, increment count 
        // and put x1 in the map.
        
        int count = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i< n; i++){
            int temp = k - arr[i];
            if(mp.find(temp)!=mp.end()){ // we found the element
                count += mp[temp];
            } 
            mp[arr[i]]++;
        }
        return count;
    }
};
