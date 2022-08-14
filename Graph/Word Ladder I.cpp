/* Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.

Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".

Expected Time Compelxity: O(N2 * M)
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi| */

//code
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        map<string, vector<string>>m;
        int msize = startWord.size();
        
        for(int i = 0; i<wordList.size(); i++){
            string str = wordList[i];
            
            for(int j = 0; j<msize; j++){
                string x = str.substr(0,j) + '*' + str.substr(j+1, msize-j-1);
                m[x].push_back(str);
            }
        }
        string str = startWord;
        for(int j = 0; j<msize; j++){
            string x = str.substr(0,j) + '*' + str.substr(j+1, msize-j-1);
            m[x].push_back(str);
        }
        
        queue<pair<string,int>>q;
        q.push({startWord,1});
        set<string> visited;
        
        visited.insert(startWord);
        
        while(!q.empty()){
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for(int j = 0; j<msize; j++){
                string p = str.substr(0,j) + "*" + str.substr(j+1,msize-j-1);
                vector<string> v = m[p];
                
                for(string x:v){
                    if(visited.find(x) == visited.end()){
                        q.push({x,level+1});
                        visited.insert(x);
                        
                        if(x == targetWord)return level+1;
                    }
                }
            }
        }
        return 0;
    }
};
