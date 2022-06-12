/*
Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'. The task is to verify the validity of the arrangement.
Note: Ignore the precedence of brackets.

Example 1:

Input:
S = ()[]{}
Output: 1
Explanation: The arrangement is valid. */

bool valid(string s)
{
    // code here
    stack<int> st;
    bool ans = true;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
               st.pop(); 
            }
            else{
                ans = false;
                break;
            }
            
        }
        else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
               st.pop(); 
            }
            else{
                ans = false;
                break;
            }
            
        }
        else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
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
