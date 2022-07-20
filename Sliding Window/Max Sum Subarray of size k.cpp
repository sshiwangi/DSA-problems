/* Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

Example 1:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1) */

class Solution {
  public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long i = 0;
        long j = 0;
        long sum = 0;
        long mx = INT_MIN;
        // we will take two pointer i and j that will take care of the size of window
        // we will keep moving until j pointer reaches the end of the array
        // if the window size is less than k, we will keep moving j pointer
        // as we hit the window size of k, we will do the calculation and store the maxm of sums so far
        // now that we got ans of 1 window, we will remove arr[i] from the sum and move the i pointer
        while(j<N){
            sum += Arr[j];
            
            if((j-i+1) < K){
                j++;
            }
            else if((j-i+1) == K){
                mx = max(mx,sum);
                
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};
