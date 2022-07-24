/* Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array.  */

//code
class Solution
{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        // map to store frequency of the elements
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        vector<int> ans; // ans to store the repeated elements
        for(auto it: mp){
            if(it.second > 1){ // if the freq of element is more than 1
                ans.push_back(it.first); // we got a repeated element
            }
        }
        sort(ans.begin(),ans.end());
        // if don't find any repeated element
        if(ans.size()==0) return {-1};
        return ans;
    }
};
