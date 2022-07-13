/* Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

*/

class Solution{
    public:
    // we need to take care of 3 attributes associated with each element of the array
    class element{
        public:
        int value;
        int index;
        int row;
        
        element(int val, int indexnum, int rownum){
            value = val;
            index = indexnum;
            row = rownum;
        }
    };
    // this will make sure the element with minm value will always be at top in min heap
    struct compare{
        bool operator()(element a, element b){
            return a.value > b.value;
        }
    };
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int mn = INT_MAX;
          int mx = INT_MIN;
          int range = INT_MAX;
          // declaring a min heap
          priority_queue<element, vector<element>, compare>q;
          int low, high; // this will store our answer
          
          // traverse in the array and store the first element of each row in the min heap
          for(int i = 0; i<k; i++){
              q.push(element(KSortedArray[i][0],0,i));
              mn = min(mn,KSortedArray[i][0]);
              mx = max(mx,KSortedArray[i][0]);
          }
          // we will pop out the top element and go to the next element in whichever array
          // the popped element belongs to and insert that in min heap and keep updating the mn,mx,
          // low,high and range
          while(!q.empty()){
              element temp = q.top();
              q.pop();
              int maybeminm = temp.value;
              
              if(range>mx-maybeminm){
                  mn = maybeminm;
                  range = mx-mn;
                  low = mn;
                  high = mx;
              }
              // if the popped element doesnot have any further element in its array,break out of the loop
              if(temp.index == n-1){
                  break;
              }
              // other wise go to the next index in the array temp belongs to
              temp.index += 1;
              // and push the element in the heap
              q.push(element(KSortedArray[temp.row][temp.index],temp.index,temp.row));
              // since the top element will always be minimum, the only thing we need to take
              // care of is mx. so keep updating maximum each time we push new element in the heap
              mx = max(mx,KSortedArray[temp.row][temp.index]);
          }
          // store the low and high in pair and return it
          pair<int,int> ans;
          ans.first = low;
          ans.second = high;
          return ans;
    }
};
