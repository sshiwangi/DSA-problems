/* Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 
 
Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n) */

//code
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    bool flag = false;
    // store the array 1 element in map
    for(int i = 0; i<n; i++){
        mp[a1[i]]++;
    }
    // iterate in array to and check if all the elements are present in map or not.
    // if any of the element is not present in map, return no
    for(int i = 0; i<m; i++){
        if(mp.find(a2[i])!=mp.end()){
            flag = true;
        }
        else{
            flag = false;
            return "No";
        }
    }
    if(flag){
        return "Yes";
    }
}
