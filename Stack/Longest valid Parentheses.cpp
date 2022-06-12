/*
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Example 1:

Input: S = ((()
Output: 2
Explaination: The longest valid 
parenthesis substring is "()". */

class Solution{
public:

/* Step1: Find those indexes at which the string is becoming unbalanced
   Step 2: if the char is '(', insert its index number in the stack.
   Step 3: if the char is ')'
            check if the top most element is '(' this or not
            if yes, then pop the index number out of the stack.
            if not, then push the index number of '('
    Step4: Create a variable that will tell us the terminal ending index of substring 
            into consideration and initialise the variable with the length of the string.
    Step 5: Traverse in the stack until the stack becomes empty and each time count the difference
            of endterminal - startterminal(the top most element in the stack) - 1 and update the maxlen
            and endterminal.
    */
    
    int maxLength(string S){
        // code here
        if(S.length()<2){
            return 0;
        }
        stack<int> st;
        for(int i = 0; i<S.length(); i++){
            if(S[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && S[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        int maxlen = 0;
        int endTerminal = S.length();
        
        while(!st.empty()){
            int startTerminal = st.top();
            st.pop();
            maxlen = max(maxlen,endTerminal-startTerminal-1);
            endTerminal = startTerminal;
        }
        return max(endTerminal,maxlen);
        
    }
};
