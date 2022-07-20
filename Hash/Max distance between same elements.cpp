/* Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N) */
// code

class Solution
{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n)
    {
    //Code here
    int maxlen = INT_MIN;
    unordered_map<int,int> lastoccur; // this will store last occurences of each element
    unordered_map<int,int> firstoccur; // and this will store only the first occurence of element
    
    for(int i = 0; i<n; i++){
        lastoccur[arr[i]] = i;
        // if the element is not present in firstoccur map, then only put it with it's index num 
        if(firstoccur.find(arr[i])==firstoccur.end()){
            firstoccur[arr[i]] = i;
        }
    }
    // iterate in the firstoccur map
    for(auto it: firstoccur){
        // max distance between same element will be the difference of it's last occurence and
        // first occurence
        if(lastoccur.find(it.first)!=lastoccur.end()){
            maxlen = max(maxlen,(lastoccur[it.first] - it.second));
        }
    }
    return maxlen;
    
    }
};
