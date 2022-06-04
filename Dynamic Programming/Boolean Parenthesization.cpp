class Solution{
public:
//declare a map
unordered_map<string,int> mp;
int mod = 1003;

int solve(string S, int i, int j, bool isTrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue == true){
            return S[i] == 'T';
        }
        else{
            return S[i] == 'F';
        }
    }
  //adding key in the form of string
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
   //checking whether the map has that key or not 
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    int ans = 0;
    for(int k = i+1; k<=j-1; k+=2){
        int lt = solve(S,i,k-1,true);
        int lf = solve(S,i,k-1,false);
        int rt = solve(S,k+1,j,true);
        int rf = solve(S,k+1,j,false);
        
        if(S[k] == '&'){
            if(isTrue == true){
                ans = ans+ lt*rt;
            }
            else{
                ans = ans + lf*rt + lf*rf + lt*rf;
            }
        }
        else if(S[k] == '|'){
            if(isTrue == true){
                ans = ans+ lt*rt +lf*rt + lt*rf;
            }
            else{
                ans = ans + lf*rf;
            }
        }
        else if(S[k] == '^'){
            if(isTrue == true){
                ans = ans+ lf*rt + lt*rf;
            }
            else{
                ans = ans + lt*rt + lf*rf;
            }
        }
    }
    return mp[temp] = ans%mod;
}
    int countWays(int N, string S){
        // code here
        int i, j;
        
        mp.clear();
        return solve(S,0,N-1,true)%mod;
    }
};
