/* Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13. 

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1) */

// code
class Solution
{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            v[i] = A[i];
        }
        sort(v.begin(),v.end());
        
        for(int i = 0; i<n; i++){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                // if sum greater than x
            if((v[i] + v[lo] + v[hi])>X){
                hi--;
            }
            // if sum less than x
            else if((v[i] + v[lo] + v[hi])<X){
                lo++;
            }
            // if the sum equal to x
            else if((v[i] + v[lo] + v[hi])== X){
                return true;
            }
            }
            
        }
        return false;
    }

};
