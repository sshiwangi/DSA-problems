class Solution{
public:
	int minDifference(int arr[], int n)  { 
	    //calculating the sum of array and storing it in variable named range
	    int range = 0;
	    for(int i = 0; i<n; i++){
	        range = range + arr[i];
	    }
	    //declare a matrix to store the values
	    int t[n+1][range+1];
	    //initializing first row and column
      for(int i = 0; i<n+1; i++){
          for(int j = 0; j<range+1; j++){
              if(i==0){
                  t[i][j] = false;
              }
              if(j==0){
                  t[i][j] = true;
              }
          }
      }
      // filling other rows and column with true or false
      for(int i = 1; i<n+1; i++){
          for(int j = 1; j<range+1; j++){
              if(arr[i-1]<=j){
                  t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
              }
              else{
                  t[i][j] = t[i-1][j];
              }
          }
      }
      // declare a vector
      vector<int> v;
      for(int j = 0; j<=range/2; j++){
          if(t[n][j] == true){ // if the last row of the matrix has true as its value then push it in vector v
              v.push_back(j);
          }
      }
      int ans = INT_MAX;
      // iterate over elements of vector
      for(int i = 0; i<v.size(); i++){
          // and calculate the minimum between the ans and range-2s[i]
          ans = min(ans,range-2*v[i]);
      }
      return ans;
  
	} 
};
