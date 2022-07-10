/* Given a sorted array, arr[] of N integers, and a value X. Find the K closest elements to X in arr[].
Keep the following points in mind:

If X is present in the array, then it need not be considered.
If there are two elements with the same difference with X, the greater element is given priority.
If sufficient elements are not present on the right side then take elements from left and vice versa.
 
Example 1:

Input:
N = 13
arr[] = {12, 16, 22, 30, 35, 39, 42, 
         45, 48, 50, 53, 55, 56}
K = 4, X = 35
Output: 39 30 42 45
Explanation: 
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.

Expected Time Complexity: O(logN + K)
Expected Auxiliary Space: O(1)

*/

class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // take a max heap which stores the number and its absolute distance 
        //from the given element x
        priority_queue<pair<int,int>> maxh;
        vector<int> ans;
        //the reason it is not running for those test cases where we have 
        //two elements with the same difference is because we are using max heap which means 
        //the largest value should be at top. it works as we are sorting the elements based 
        //on difference and not the element itself but when it comes to the same difference case,
        // it will try sorting on the basis of the elemets and put that element at the top whose 
        //value is maximum as the question suggests we have to make sure that the minimum value 
        //element goes to top so multiply the elements with -1 and then push it in the queue.
        for(int i = 0; i<n; i++){
            int diff = abs(arr[i]-x);
            if(diff!=0){
               maxh.push({diff,-1* arr[i]});
               if(maxh.size()>k){
                  maxh.pop();
                }  
            }
            
        }
        while(maxh.size()>0){
            ans.push_back(-1 * maxh.top().second);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
