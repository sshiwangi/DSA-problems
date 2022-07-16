/* Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Example 1:
 
Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). */
// code

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int currsum = 0;
        int currlen = 0;
        int maxlen = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0; i<N; i++){
            currsum += A[i];
            // if currsum == k
            if(currsum - K == 0){
                currlen = i + 1;
                maxlen = max(maxlen,currlen);
            }
            currlen = 0;
            // if we find currsum - k in the map
            if(mp.find(currsum - K)!=mp.end() ){
                currlen = i - mp[currsum-K];
                maxlen = max(maxlen,currlen);
            }
            // if mp doesnot contain currsum, then only insert it
            if(mp.find(currsum) == mp.end()) {
                mp[currsum] = i;
            }
        }
        if(maxlen){
            return maxlen;
        }
        else{
            return 0;
        }
        
    } 

};
