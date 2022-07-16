/* You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
Example 1:
Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n) */
// code

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll,ll> mp;
        ll count = 0;
        ll currsum = 0;
        
        for(int i = 0; i<n; i++){
            currsum += arr[i];
            
            if(currsum == 0){
                count++;
            }
            if(mp.find(currsum)!=mp.end()){
                count = count + mp[currsum];
            }
            // if(mp.find(currsum)==mp.end()){
                mp[currsum]++;
            // }
        }
        return count;
    }
};
