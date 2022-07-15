/*
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */

// code

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        // map to store the frequency of elements of array
        unordered_map<int,int> mp;
        vector<int> ans;
        // traverse in the first window and add store the elements in the map
        for(int i = 0; i<k; i++){
            mp[A[i]] ++;
        }
        ans.push_back(mp.size());
        // for other window of size k, each time you add a new element in map, make sure you
        // decrease the frequency by 1 of the element that goes out of bound.
        for(int i = k; i<n; i++){
            mp[A[i]] ++;
            mp[A[i-k]] = mp[A[i-k]] - 1;
            // if the frequency of that element becomes 0, remove it from the map
            if(mp[A[i-k]] == 0) mp.erase(A[i-k]);
            ans.push_back(mp.size());
        }
        return ans;
    }
};
