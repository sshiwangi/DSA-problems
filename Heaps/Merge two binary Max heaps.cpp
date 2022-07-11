/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m) */

//code

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i)  
    {
      // Your Code Here
      int largest = i;
      int l = 2*i + 1;
      int r = 2*i + 2;
      
      if(l<n && arr[l] > arr[largest]){
          largest = l;
      }
      if(r<n && arr[r] > arr[largest]){
          largest = r;
      }
      if(largest != i){
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
      }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
       // just put the two vectors in a new vector and call heapify function for the newer vector
        for(int i = 0; i<n; i++){
            ans.push_back(a[i]);
        }
        for(int i = 0; i<m; i++){
            ans.push_back(b[i]);
        }
        int s = ans.size();
        for(int i = (s/2)-1; i>=0; i--){
            heapify(ans,s,i);
        }
   
        return ans;
    }
};
