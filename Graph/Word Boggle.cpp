/* Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a 
sequence of adjacent characters on the board. We can move to any of 8 adjacent characters

Note: While forming a word we can move to any of the 8 adjacent cells. A cell can be used only once in one word.

Example 1:

Input: 
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation: 
C A P
A N D
T I E
Words we got is denoted using same color.

Expected Time Complexity: O(N*W + R*C^2)
Expected Auxiliary Space: O(N*W + R*C)


Constraints:
1 ≤ N ≤ 15
1 ≤ R, C ≤ 50
1 ≤ length of Word ≤ 60
Each word can consist of both lowercase and uppercase letters. */

//code
public:
    bool dfs(vector<vector<char> >& board, string &word, int i, int j, int n, int m, int idx){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[idx] ){ // if the cordinate is invalide
            return false;
        }
        if(idx == word.size()-1){ //if we are done with the first word
            return true;
        }
        
        char temp = board[i][j];
        board[i][j] = '0';
        
        // call for all it's adjacent
       bool a = dfs(board,word,i,j+1,n,m,idx+1);
       bool b= dfs(board,word,i,j-1,n,m,idx+1);
       bool c = dfs(board,word,i+1,j,n,m,idx+1);
       bool d = dfs(board,word,i-1,j,n,m,idx+1);
       bool e = dfs(board,word,i+1,j+1,n,m,idx+1);
       bool f = dfs(board,word,i-1,j+1,n,m,idx+1);
       bool g = dfs(board,word,i+1,j-1,n,m,idx+1);
       bool h = dfs(board,word,i-1,j-1,n,m,idx+1);
       
        board[i][j] = temp;
        return a||b||c||e||f||g||h||d;
            
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    int n = board.size(); // rows
	    int m = board[0].size(); //column
	    
	    vector<string> ans;
	    set<string> unique;
	    for(int k = 0; k<dictionary.size(); k++){
	        string word = dictionary[k];
	        int len = word.size();
	        for(int i = 0; i< n; i++){
	            for(int j = 0; j<m; j++){
	                
	               if(dfs(board,word,i,j,n,m,0)){
	                   unique.insert(word); // if word present in board, put it in the answer vector
	               }
	           
	            }
	        }
	    }
	    for(auto it: unique){
	        ans.push_back(it);
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};
