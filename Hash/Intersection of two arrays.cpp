/* Given two arrays a[] and b[] respectively of size n and m, the task is to print the count of elements in the intersection (or common elements) of the two arrays.

For this question, the intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Example 1:

Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1

Explanation: 
89 is the only element 
in the intersection of two arrays.

Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(min(n,m)). */

// code

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_map<int,int> mp;
        int count = 0;
        
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
        for(int j=0; j<m; j++){
            if(mp.find(b[j])!=mp.end()){
                count++;
                mp.erase(b[j]);
            }
        }
        return count;
    }
};
