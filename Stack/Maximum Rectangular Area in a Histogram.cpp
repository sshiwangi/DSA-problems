/* Problem Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12 */


class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
      stack<pair<long long,long long>>s1; //left
      stack<pair<long long,long long>>s2; //right
      vector<long long>v1;
      vector<long long>v2;
      
      // Finding the Index of Next smaller element to left
      
      for(long long i = 0;i<n;i++){
          if(s1.size()==0){
              v1.push_back(-1);
          }
          else if(s1.size()>0 && s1.top().first<arr[i]){
              v1.push_back(s1.top().second);
          }
          else if(s1.size()>0 && s1.top().first>=arr[i]){
              while(s1.size()>0 && s1.top().first>=arr[i]){
                  s1.pop();
              }
              if(s1.size()==0){
                  v1.push_back(-1);
              }
              else{
                  v1.push_back(s1.top().second);
              }
              
          }
          s1.push({arr[i],i});
      }
      // Finding index of next smaller element to right
      for(long long i = n-1;i>=0;i--){
          if(s2.size()==0){
              v2.push_back(n);
          }
          else if(s2.size()>0 && s2.top().first<arr[i]){
              v2.push_back(s2.top().second);
          }
          else if(s2.size()>0 && s2.top().first>=arr[i]){
              while(s2.size()>0 && s2.top().first>=arr[i]){
                  s2.pop();
              }
              if(s2.size()==0){
                  v2.push_back(n);
              }
              else{
                  v2.push_back(s2.top().second);
              }
              
          }
          s2.push({arr[i],i});
      }
      reverse(v2.begin(),v2.end());
      // storing the area in v2
      for(long long i = 0;i<v2.size();i++){
          v2[i] = (v2[i]-v1[i]-1)*arr[i];
      }
      //returning the maximum area
      return *max_element(v2.begin(),v2.end());
    }
}
