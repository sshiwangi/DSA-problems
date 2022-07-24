/* Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 
Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1). */

//code
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ans = INT_MIN;
        unordered_map<int,int> mp;
        for(int i = 0; i<size; i++){
            mp[a[i]]++;
        }
        for(auto it: mp){
            if(it.second > (size/2)){ // if the freq of element is more than n/2
                ans = it.first; // we got our answer
                break;
            }
        }
        if(ans == INT_MIN){
            return -1;
        }
        else return ans;
        
    }
};
