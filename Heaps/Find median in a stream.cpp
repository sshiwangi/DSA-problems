/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n) */
// code
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    void insertHeap(int &x)
    { // the maxh is empty, push it or if maxh has element which is greater than x 
    //then also push x in maxh.
         if(minh.size()==0) minh.push(x);

        else if(maxh.size()==0) maxh.push(x);

        else{

            if(maxh.top()<x) minh.push(x);

            else maxh.push(x);

        }
       
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        // if at any time the difference of sizes of the two heaps exceeds 1,
        // we need to balance them by transfering the top element of larger size heap to ohter.
        
        while(maxh.size() + 1 < minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
        while(maxh.size()>minh.size()){
            minh.push(maxh.top());
            maxh.pop();
        }
       
    }
    
    //Function to return Median.
    double getMedian()
    {
        balanceHeaps();
        double ans = 0;
        if(maxh.size()+ minh.size() == 0) return ans;
        if((maxh.size() + minh.size())%2==0){
            ans = ((maxh.top()*1.0 + minh.top()*1.0))/2;
            
        }
        else{
            ans = minh.top();
            
        }
        return ans;
        /
    }
};
