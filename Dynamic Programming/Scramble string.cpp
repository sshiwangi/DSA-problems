class Solution {
public:
    // Declaring a map
    unordered_map<string,bool> mp;
    bool solve(string s1, string s2){
        // if both strings are same then they are scrambled strings
        if(s1.compare(s2) == 0){
            return true;
        }
        // the length of s1 can not be less than one cause empty string is not allowed and if its length is equal to 1 then it must be equal to s2
        if(s1.length() <= 1){
            return false;
        }
        // storing key in map
        string key = s1;
        key += " ";
        key += s2;
        // if key is present then return its value
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n = s1.length();
        // if the strings are scrampled by either swapping or non - swapping return true
        for(int i = 1; i<=n-1; i++){
            if(solve(s1.substr(0,i) , s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i)) || solve(s1.substr(0,i),s2.substr(0,i))  && solve(s1.substr(i,n-i),s2.substr(i,n-i))){
                return mp[key] = true;
                
            }
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        // if the length of the string are unequal it can never be scrambled so return false
        if(s1.length()!=s2.length()){
            return false;
        }
        
        if(s1.length() == 0 && s2.length() == 0){
            return true;
        }
        return solve(s1,s2);
    }
    
};
