/* Problem link-> https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1/?page=2&category[]=Stack&sortBy=submissions# 

Given a String. Reverse each word in it where the words are separated by dots.

Example 1:

Input:
S = "i.like.this.program.very.much"
Output: 
i.ekil.siht.margorp.yrev.hcum
Explanation: 
The words are reversed as
follows:"i" -> "i","like"->"ekil",
"this"->"siht","program" -> "margorp",
"very" -> "yrev","much" -> "hcum". */

class solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        // iterate in the string and put the charachters in the stack until found a dot.
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            stack<char> st;
            while(s[i]!='.' && i<s.length()){
                st.push(s[i]);
                i++;
            }
            // pop the charachters out of the stack and add dot at the end
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            // add dot after each word except the last one.
            if(i!=s.length()){
                ans+='.';
            }
            
        }
        return ans;
    }
};
