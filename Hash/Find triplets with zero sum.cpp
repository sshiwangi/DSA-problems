/* Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1) */

// code
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code he
        vector<int> v(n);
        for(int i=0;i<n;i++)
        v[i]=arr[i];
        
        sort(v.begin(),v.end());
        for(int i = 0; i<n; i++){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if((v[i]+v[lo]+v[hi])<0) lo++;
                else if((v[i]+v[lo]+v[hi])>0) hi--;
                else return true; // the triplet is 0
            }
        }
        return false;
    }
};
