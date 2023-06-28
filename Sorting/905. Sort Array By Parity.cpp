/* Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000 */
//code
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                odd.push_back(nums[i]);
            }
            else even.push_back(nums[i]);
        }
        vector<int>ans;
        for(int i = 0; i<even.size(); i++){
             ans.push_back(even[i]);
          
        }

        for(int i = 0; i<odd.size(); i++){
             ans.push_back(odd[i]);
        }
        return ans;
    }
        
};
