/* Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10

Expected Time Complexity : O(nlogk)
Expected Auxilliary Space : O(n) */
// code

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> ans;
        // take a min heap and store the array elements in it
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i = 0; i<num; i++){
            minh.push(arr[i]);
        }
        // take out elemets from the top one by one and push it in answer
        while(minh.size()>0){
            int ele = minh.top();
            ans.push_back(ele);
            minh.pop();
        }
        // returning the sorted answer
        return ans;
    }
};
