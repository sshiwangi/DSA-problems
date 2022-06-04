class solution {
public:
	int t[1001][1001];
	int Lcs(string str1, string str2, int m){
	    
	    for(int i = 0; i<m+1; i++){
            for(int j = 0;j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        //filling other rows and columns of the matrix
        for(int i = 1; i<m+1; i++){
            for(int j = 1;j<m+1; j++){
                if(str1[i-1] == str2[j-1] && i!=j){
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][m];
	}
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int m = str.length();
		    return Lcs(str,str,m);
		}
};
