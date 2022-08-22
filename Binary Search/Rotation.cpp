/* Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:

Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4. 
The original sorted array is 1 2 3 4 5. 
We can see that the array was rotated 
1 times to the right.

Your Task:
Complete the function findKRotation() which takes array arr and size n, as input parameters and returns an integer representing the answer. 
You don't to print answer or take inputs.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <=105
1 <= Arri <= 107 */

//code
class Solution{
public:	
// we will find out the minimum element and return it's index, that will be the value of k that is
// no of rotation.
	int findKRotation(int arr[], int n) {
	    // code here
	    int start = 0;
	    int end = n-1;
	    
	    while(start<=end){
	        int mid = start + (end - start)/2;
	        int next = (mid + 1) % n; // modulo n so that it doesn't go out of bound
	        int prev = (mid + n - 1)%n;
	        // minimum element will be less than both it's previous and next element
	        if(arr[mid]<= arr[next] && arr[mid]<=arr[prev]){
	            return mid;
	        }
	        else if(arr[0] <= arr[mid]) start = mid +1; // if unsorted array lies right side, go in that direction
	        else end = mid - 1; // else go in left that direction
	    }
	    return 0;
	}

};
