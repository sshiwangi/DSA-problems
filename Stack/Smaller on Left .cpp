/*
Given an array arr[ ] of N positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".

Example 1:

Input:
N = 5
arr[] = {2, 3, 4, 5, 1}
Output: 
-1 2 3 4 -1
Explanation:
Greatest element on the left of 3 smaller 
than itself is 2, for 4 it is 3 and for 5 
it is 1. Since 2 is the first element and 
no element on its left is present, so it's 
greatest smaller element will be -1 and for 
1 no element smaller than itself is present 
on its left, so it's greatest smaller element 
is -1. */

// code

vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int> v;
    set<int> s;
    // lower bound return immediatie greater element
    // auto detects the type by itself
    
    for(int i = 0; i<=n-1; i++){
        auto index = s.lower_bound(arr[i]); // the index here is the address of the element
        if(index == s.begin()){ // if the pointer is at the first element then it means there is 
        // no element in the set so just push -1
            v.push_back(-1);
        }
        else{
            index--;
            v.push_back(*index); // if the pointer is at 3, then the lower bound will return s.end()
            // because there is no element in the set greater than the element, so in order to return 2
            // do it-- and push the value at that address in the vector.
        }
        s.insert(arr[i]);
        
    }
    return v;
}
