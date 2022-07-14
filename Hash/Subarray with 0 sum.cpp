/* Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n). */

// code
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int currsum = 0;
        int start = 0;
        int end = -1;
        unordered_map<int,int> mp;
        
        for(int i = 0; i<n; i++){
            currsum += arr[i];
            
            if(currsum == 0){
                return true;
            }
            // if currsum already present in map
            if(mp.find(currsum)!=mp.end()){
                return true;
            }
            // put currsum along wiht the index i in the map
            mp[currsum] = i;
        }
        return false;
    }
};
