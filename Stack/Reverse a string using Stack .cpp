/* 
You are given a string S, the task is to reverse the string using stack.

Example 1:

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    // traverse in the string and push the elements in the stack
    for(int i = 0; i<len; i++){
        st.push(S[i]);
    }
    // traverse in the string and add the elements coming out from the stack
    for(int i = 0; i<len; i++){
        S[i] = st.top();
        st.pop();
    }
    return S;
}
