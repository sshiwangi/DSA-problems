/*
You are given a stack St. You have to reverse the stack using recursion.

 

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */

// code
class Solution{
public:
// since the space complexity is o(n), there is no need of to 2 recursive calls
// simply pop the elements one by one out of the stack and push back in the answer vector.
       void solve(vector<int>&v,stack<int>&st){
       if(st.size()==0){
           return;
       }
       int num=st.top();
       st.pop();
       v.push_back(num);
       solve(v,st);
   }
   vector<int> Reverse(stack<int> st){
       vector<int>v;
       solve(v,st);
       return v;
   }
};
