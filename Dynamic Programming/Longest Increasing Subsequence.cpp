class Solution
{
    public:
  //Function to find length of longest increasing subsequence.
  //binary search approach
    int longestSubsequence(int n, int a[])
    {
       vector<int> temp; // this will not give longest increasing subsequence, it will only give its length
       temp.push_back(a[0]); // inserting first element
       int len = 1; 
       // iterate over array
       for(int i = 0; i<n; i++){
           //if the element is greater than the element in temp, insert in temp
           if(a[i]>temp.back()){
               // and increase the len
               temp.push_back(a[i]);
               len++;
           }
           // otherwise find the index of the element where we need to overwrite a[i]
           else{
               int ind = lower_bound(temp.begin(), temp.end(), a[i]) -temp.begin();
               // overwrite the element at the index to a[i]
               temp[ind] = a[i];
           }
       }
       // finally return the length
       return len;
    
    }
};
