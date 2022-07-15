/* Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

//code
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int currsum = 0;
        int maxlen = 0;
        int currlen = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i = 0; i<n; i++){
            currsum += A[i];
            // if currsum present in map
            if(mp.find(currsum)!=mp.end()){
                currlen = currlen + (i - mp[currsum]);
                maxlen = max(currlen, maxlen);
                currlen = 0;
            }
            // insert currsum wiht its index
            else{
                mp[currsum] = i;
            }
            
        }
        if(maxlen){
            return maxlen;
        }
        else{
            return 0;
        }
    }
};
