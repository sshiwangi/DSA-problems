class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int sum = 0, minsum = INT_MAX;
      for(int i = 0; i<a.size(); i++){
          sum += a[i];
          minsum = min(minsum, sum);
          if(sum>0){
              sum = 0;
          }
      }
      return minsum;
  }
};
