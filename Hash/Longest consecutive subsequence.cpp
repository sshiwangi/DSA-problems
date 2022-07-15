/* Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 
Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code
class Solution
{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      /* Algorithm:
      1. insert all elements in array
      2. traverse in arr and check if arr[i-1] is present or not
          if present, don't do anything
          if not present, this can be the first element of the sequence
              so check if it is present in hash map or not, if present increment count by 1
              and check for the next consecutive numbers */  
        unordered_set<int> s;
        for(int i = 0; i<N; i++){
            s.insert(arr[i]);
        }
        
        int ans = 0;
        for(int i = 0; i<N; i++){
            if(s.find(arr[i]-1) != s.end()){
                continue;
            }
            else{
                int count = 0;
                int current = arr[i];
                while(s.find(current)!= s.end()){
                    count++;
                    current++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
      
    }
};
