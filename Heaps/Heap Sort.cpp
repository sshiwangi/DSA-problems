/*
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.
Example 1:
Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1). */

// code

class Solution
{
    public:
    // steps: first we will convert the given array or into heap using heapify function
    // then we will delete the element one by one from top as the top of maxheap is always the
    // largest. then we wil get our sorted array 
    // Time complexity will be, 0(n) for heapify and logn for sorting one time. so time will 
    // be 0(nlogn)
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
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

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i = (n-2)/2; i>=0; i--){
        heapify(arr,n,i);
    }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i = n-1; i>=0; i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
