/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n) */

// code
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Take a min heap
      // we will iterate over the array and store the elements in the min heap.
      // doing this the minimum length ropes will be at top and we can take the 2 ropes from tops, count their cost and push back the sum of their length back in the heap.
        priority_queue<long long, vector<long long>, greater<long long>> minh;
        for(int i = 0; i<n; i++){
            minh.push(arr[i]);
        }
        long long cost = 0;
        while(minh.size()>=2){
            long long rope1 = minh.top();
            minh.pop();
            long long rope2 = minh.top();
            minh.pop();
            cost = cost + rope1 + rope2;
            minh.push(rope1+rope2);
        }
        return cost;
        
    }
};
