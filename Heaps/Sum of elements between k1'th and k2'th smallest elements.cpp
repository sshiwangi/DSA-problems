/* Given an array A[] of N positive integers and two positive integers K1 and K2. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

Example 1:

Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20 
12,14. Their sum = 26.

Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N) */

// code
class Solution {
    public:
  // Function to find kth smallest element in an array
    long long kthsmallest(long long A[],long long N, long long K){
        priority_queue<int> maxh;
        for(int i = 0; i<N; i++){
            maxh.push(A[i]);
            if(maxh.size()>K){
                maxh.pop();
            }
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first = kthsmallest(A,N,K1);
        long long second = kthsmallest(A,N,K2);
        long long sum = 0;
      // add the elements in sum lying between first and second
        for(int i = 0; i<N; i++){
            if(A[i] > first && A[i] < second){
                sum = sum + A[i];
            }
        }
        return sum;
    }
};
