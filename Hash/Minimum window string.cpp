/* Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1) */

{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int>map;
        unordered_map<int, int>ans;  //map to store the size and initial index of answer window
        for(auto x : p) map[x]++;
        int i = 0, j = 0, count = map.size(), minSizeLen = INT_MAX, n = s.size();
        bool flag = true;
        while(j<n){
            // if we find the element in map
            if(map.find(s[j]) != map.end()){
               { 
                map[s[j]]--; // decrement it's value by 1
                if(map[s[j]] == 0) count--; //  If any character's count in the map becomes zero, decrementing the count variable
               }
            }
            if(count > 0) j++;
            // if we got a candidate for the answer
            else if (count == 0){
                flag = false;
                // start incrementing i pointer to optimize the answer
                while(count == 0){
                    // find the min length
                    minSizeLen = min(minSizeLen, j-i+1);
                    if(ans.find(minSizeLen) == ans.end())
                      ans[minSizeLen] = i; // Storing the minimum size of the window and initial index of string window
                    if(map.find(s[i]) != map.end()) // if s[i] is present in map
                    {
                        map[s[i]]++; // increment it's value
                        if(map[s[i]] == 1) count++; // If any character's count in the map becomes 1 from zero, incrementing count //variable
                    }
                    // if not present, simply move i pointer and don't do anything
                    i++;
                }
                // if count is no more 0, start moving j pointer again
                j++;
            }
        }
        // if we didn't find any such window
        if(flag) return "-1";
        string a;
        // if we find the minimum length window
        for(int j = ans[minSizeLen]; j< ans[minSizeLen] + minSizeLen; j++) a.push_back(s[j]);
        return a;
    }   
};
