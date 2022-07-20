/* Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should be given preference. 

Note: Print the elements according to the frequency count (from highest to lowest) and if the frequency is equal then larger number will be given preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N) */

//code
class Solution
{
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>>maxh;
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        // storing the frequency of elements in map
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        // iterate in map and push elements with it's frequency in minh
        for(auto it: mp){
            minh.push({it.second,it.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        // after this for loop, min hoop will contain k most frequent elements
        // but the top element will be small
        while(minh.size()>0){
            auto topEle = minh.top();
            maxh.push(topEle);
            minh.pop();
        }
        // so push each element in maxh so that we can get most frequent elemetn first
        while(maxh.size()>0){
            ans.push_back(maxh.top().second); // store the element in ans
            maxh.pop();
        } // return ans
        return ans;
    }
};
