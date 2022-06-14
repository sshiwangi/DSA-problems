/*Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6. */

// Code
// This problem is the variation of next greater element to left problem
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> v;
       // declare a stack that stores pair,NGL and index of the NGL
        stack<pair<int,int>> s;
        
        for(int i = 0; i<n; i++){
            if(s.empty()){
                v.push_back(-1);
            }
            // Compare with the first element of the stack that is the next greater element to left
            else if(!s.empty() && s.top().first > price[i]){
                v.push_back(s.top().second); // and push the index of ngl in the vector which is the second of the stack
            }
            else if(!s.empty() && s.top().first <= price[i]){
                while(!s.empty() && s.top().first <= price[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push({price[i],i});
        }
        // v = [-1,0,1,1,3,1,0]
        // traverse in the vector and subtract the element from the index
        for(int i = 0; i<v.size(); i++){
            v[i] = i-v[i];
        }
        // return the resultant vector
        // v = [1,1,1,2,1,4,6]
        return v;
    }
};
