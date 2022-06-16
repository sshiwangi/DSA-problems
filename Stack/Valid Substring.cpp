/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2. */

// code

class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        if(s.length()<2){
            return 0;
        }
        stack<int> st;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        int maxlen = 0;
        int endTerminal = s.length();
        
        while(!st.empty()){
            int startTerminal = st.top();
            st.pop();
            maxlen = max(maxlen,endTerminal-startTerminal-1);
            endTerminal = startTerminal;
        }
        return max(endTerminal,maxlen);
        
    }
};
