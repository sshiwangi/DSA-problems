/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.

 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets) */

// code
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> maxh;
        for(auto x: str)
            freq[x]++;
        
        for(auto it: freq)
            maxh.push({it.second, it.first});
        
        str = "";
        while(maxh.size() > 1){
            auto top1 = maxh.top();
            maxh.pop();
            auto top2 = maxh.top();
            maxh.pop();
            
            // this will put only different characters together
            str += top1.second;
            str += top2.second;
            
            if(--top1.first > 0)
                maxh.push(top1);
            if(--top2.first > 0)
                maxh.push(top2);
            
        }
        
        if(maxh.size()){
            // if the last char's freq is 1, simply add in the ans
            if(maxh.top().first == 1)
                str += maxh.top().second;
            else
            // if it's freq is more than 1, there is no way they can't be put together, so return -1
                return "-1";
        }
        
        return str;
    }
    
};
