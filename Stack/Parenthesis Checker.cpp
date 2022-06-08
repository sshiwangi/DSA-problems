/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket. */

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        bool ans = true;
        for(int i = 0; i<x.length(); i++){
            if(x[i] == '(' || x[i] == '[' || x[i] == '{'){
                st.push(x[i]);
            }
            else if(x[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
                
            }
            else if(x[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
                
            }
            else if(x[i] == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    ans = false;
                    break;
                }
                
            }
            
        }
        while(!st.empty()){
            return false;
        }
        return ans;
    }

};
