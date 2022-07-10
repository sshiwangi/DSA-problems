/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].

Expected Time Complexity: O(K2*Log(K))
Expected Auxiliary Space: O(K)*/
// code

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        priority_queue<int> maxh;
        // just store each element in maxh, it will sort it itself
        for(int i = 0; i<K; i++){
            for(int j = 0; j<K; j++){
                maxh.push(arr[i][j]);
            }
        }
        while(maxh.size()>0){
            int ele = maxh.top();
            ans.push_back(ele);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
