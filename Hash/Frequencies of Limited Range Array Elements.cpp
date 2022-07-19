/*
Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
Note: The elements greater than N in the array can be ignored for counting and please read your task section of the problem carefully to understand how to output the array.

Example 1:

Input:
N = 5
arr[] = {2, 3, 2, 3, 5}
P = 5
Output:
0 2 2 0 1
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.

Your Task:
Complete the function frequencycount() that takes the array and n as input parameters and modify the array itself in place to denote the frequency count of each element from 1 to N. i,e element at index 0 should represent the frequency of 1 and so on.


Note: Can you solve this problem without using extra space (O(1) Space) !


Constraints:
1 ≤ N ≤ 105
1 ≤ P ≤ 4*104 
1 <= A[i] <= P */

// code
class Solution
{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        // declare a vector named freq of size maxi+1(for 0 based indexing)  and initialize it with 0
        int maxi = max(P,N);
        vector<int> freq(maxi+1,0);
        
        // storing the count of elements in freq
        for(int i = 0; i<N; i++){
            if(arr[i]<=P){
                freq[arr[i]] = freq[arr[i]]+ 1;
            }
            else{
                continue;
            }
        }
        // freq = {0, 0, 2, 2, 0, 1}
        // index = 0  1  2  3  4  5
        for(int i = 0; i<N; i++){
            // storing count of each number starting from 1 in array
            arr[i] = freq[i+1];
        } // arr = { 0, 2, 2, 0, 1}
         // index =  1, 2, 3, 4, 5
    }
};
