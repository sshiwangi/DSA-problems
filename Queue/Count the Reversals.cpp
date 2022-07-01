/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).*/

// code
int countRev (string s)
{
    // if the length of the string is odd, then it could not be balanced
    if(s.length()%2 != 0){
        return -1;
    }
    
    int reversals = 0;
    stack<char> st; // the stack will store only unbalanced brackets
    
    for(int i = 0; i<s.length(); i++){
        // delete the balance pairs
        if(s[i] == '}' && !st.empty() && st.top()=='{'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    
    while(!st.empty()){
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        // if both c1 and c2 are same, then we need to only reverse one to make it a balance pair
        if(c1 == '{' && c2 == '{' || c1 == '}' && c2 == '}'){
            reversals++;
        }
        else if(c1 == '{' && c2 == '}'){
            reversals +=2;
        }
    }
    // return the answers
    return reversals;
}
