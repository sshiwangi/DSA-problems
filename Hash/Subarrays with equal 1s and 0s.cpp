/* Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:
Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n). */

//code
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        for(int i = 0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        unordered_map<long,long> mp;
        long count = 0;
        long currsum = 0;
        
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
