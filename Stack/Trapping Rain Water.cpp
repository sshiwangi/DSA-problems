/* Problem Link: 
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10 */

class Solution
{
// Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // Declaring two arrays to store the maximum height on the left and right side of buiding at ant index
        int mxl[n];
        int mxr[n];
        
        // initialize mxl with the first element of the array
        mxl[0] = arr[0];
        // initialize mxr with the last element of the array
        mxr[n-1] = arr[n-1];
        
        // traverse in the rest of the array, and fill the mxl array
        for(int i = 1; i<n;i++){
            mxl[i] = max(mxl[i-1],arr[i]);
        }
        
        for(int i = n-2; i>=0;i--){
            mxr[i] = max(mxr[i+1],arr[i]);
        }
        
        // declaring water array to store the unit of water stored on each building
        int water[n];
        for(int i = 0; i<n; i++){
            water[i] = min(mxl[i],mxr[i]) - arr[i];
        }
        // traverse in the water array and add the units of water
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum = sum + water[i];
        }
        return sum;
    }
};
