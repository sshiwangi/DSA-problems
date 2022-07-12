/*
Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22

Expected Time Complexity: O(N*logN)  where N is the length of string
Expected Auxiliary Space: O(N) */

// code

class Solution{
public:
    int minValue(string s, int k){
        //the idea is to keep decreasing the char with maximum frequency
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> maxh;
        // storing frequency of each char in map
        for(auto i: s){
            freq[i]++;
        }
        // storing the char with their freq in maxh(it will keep the maxm freq char at top)
        for(auto it: freq){
            maxh.push({it.second,it.first});
        }
        // this loop will run until k is greater than 0
        while(!maxh.empty() && k--){
            
            auto topEle = maxh.top();
            maxh.pop();
            // decrease the frequency of top element by 1, if it's still not 0, push it back
            if(--topEle.first > 0){
                maxh.push(topEle);
            }
            
        }
        // lastly take out elements one by one and add the square of them in the answer
        int sum = 0;
        while(maxh.size()>0){
            int ele = maxh.top().first;
            sum += ele * ele;
            maxh.pop();
        }
        
        return sum;
    }
};
