/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result. */

class {
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Declare a stack
        stack<int> st;
      
        for(int i = 0; i<S.length(); i++){
          // if the element in the string is an operand, simply push it in the stack
            if(S[i]>='0' && S[i]<='9'){
                st.push(S[i]-'0');
            }
          // if it is an operator then pop the top element and store it in variable op2 and the next element in op1
            else{
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                // push the number we get by performing these operations on the operand back in the stack
                switch (S[i])
                {
                case '+':
                    st.push(op1+op2);
                    break;
        
                case '-':
                   st.push(op1-op2);
                   break;
                
                case '*':
                   st.push(op1*op2);
                   break;
                
                case '/':
                   st.push(op1/op2);
                   break;
                }
            }
        }
        return st.top();
    }
};
