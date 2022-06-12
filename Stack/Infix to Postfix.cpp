/*
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i- */

/* Steps to solve this problem
1. if operand comes in the string,simply store it in result string
2. if '(', push to stack
3. if ')', pop from stack and print it until '(' is found.
4. if operator comes,pop from stack and until an operator with less precedence is found
*/

class {
public:
    // Defining precedence of the operators
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='*' || c=='/'){
            return 2;
        }
        else if(c=='+' || c=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string res;
        
        for(int i = 0; i<s.length(); i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ){
                res+=s[i];
            }
            else if(s[i]=='(' ){
                st.push(s[i]);
            }
            else if(s[i]==')' ){
                while(!st.empty() && st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && prec(st.top())>=prec(s[i])){
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
