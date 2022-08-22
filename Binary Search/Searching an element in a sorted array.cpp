/* Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.

Example 1:

Input:
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.


Expected Time Complexity: O(Log N)
Expected Auxiliary Space: O(1) */

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       int st = 0;
       int end = N-1;
       
       while(st<=end){
           int mid = st + (end-st)/2;
           
           if(K == arr[mid])return 1;
           else if(K<arr[mid]) end = mid-1;
           else if(K>arr[mid]) st = mid+1;
       }
       return -1;
      
       
    }
};
