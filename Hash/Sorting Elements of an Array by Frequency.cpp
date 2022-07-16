/* Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).  */
//code
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int>ans;
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> maxh;
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        // traverse in the map and push pair in heap
        for(auto it: freq){
            maxh.push({it.second,-1*(it.first)});
        }
        //take out the element one by one and store it in ans vector
        while(maxh.size()>0){
            int topEle = maxh.top().second;
            int topElefreq = maxh.top().first;
            maxh.pop();
            
            for(int i = 0;i<topElefreq; i++){
                ans.push_back(-1*topEle);
            }
        }
        return ans;
    }
};
