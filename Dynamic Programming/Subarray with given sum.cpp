class Solution {
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Sliding window approach
        int left = 0; 
        int right = 0;
        int sum = 0;
        vector<int>v;
        // this while loop will break at the end of the array
        while(right<n){
            sum+=arr[right];
            //this while loop will break if the sum exceeds the given sum
            while(sum>s){
                // if sum exceeds the given sum start subtracting the element from start and increment left
                sum-=arr[left];
                left++;
            }
            // if sum becomes equal to the given sum
            if(sum == s){
                // push left + 1 and right +1 into the vector ( 1 based indexing )and return it
                // 
                v.push_back(left+1);
                v.push_back(right+1);
                return v;
            }
            
            right++;
        }
        // if there aren't any subarray with given sum, push -1 into the vector and return v;
        v.push_back(-1);
        return v;
    }
};
