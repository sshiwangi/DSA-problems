class Solution {
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long int maxp = INT_MIN, prod = 1;
    //traversing in the array from left direction
	    for(int i = 0; i<n; i++){
	        prod *= arr[i];
	        maxp = max(maxp,prod);
	        if(prod == 0){
	            prod = 1;
	        }
	    }
    //after being done with 1 way of traversal, make the product = 1
	    prod = 1;
    //traversing from the right direction
	    for(int i = n-1; i>=0; i--){
	        prod *= arr[i];
	        maxp = max(maxp,prod);
	        if(prod == 0){
	            prod = 1;
	        }
	    }
	    return maxp;
	}
};
