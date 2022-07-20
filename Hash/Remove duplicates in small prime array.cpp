/* Given an array consisting of only prime numbers, remove all duplicate numbers from it. 

Example 1:

Input:
N = 6
A[] = {2,2,3,3,7,5}
Output: 2 3 7 5
Explanation: After removing the duplicate
2 and 3 we get 2 3 7 5.
Your Task:

Complete the function removeDuplicate() that takes the array of integers and N as input parameters and returns the modified array which has no duplicates. Retain only the first occurrence of the duplicate element. The elements in the returning array should be in the same order as they appear in the original array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1). */
//code

class Solution{
  public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minh;
        unordered_map<int,int> mp;
        unordered_map<int,int> firstoccurmap; // this will store first occurences of element
        
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
            
            if(firstoccurmap.find(arr[i])==firstoccurmap.end()){
                firstoccurmap[arr[i]] = i;
            }
        }
      // traverse in the firstoccur map and push the unique elements with it's first occurence index in min heap
        for(auto it: firstoccurmap){
            minh.push({it.second,it.first});
        }
        vector<int> ans;
      // min heap will have the element at lowest index at the top
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
      // return the ans
        return ans;
    }
};
