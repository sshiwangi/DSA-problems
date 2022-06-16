/* Problem Link: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?page=1&difficulty[]=0&category[]=Stack&sortBy=submissions#

Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil((size_of_stack+1)/2) (1-based index)
 

Example 1:

Input: 
Stack = {1, 2, 3, 4, 5}
Output:
ModifiedStack = {1, 2, 4, 5}
Explanation:
As the number of elements is 5 , 
hence the middle element will be the 3rd
element which is deleted

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */

// CODE

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        if(s.size()==1){
            s.pop();
            return;
        }
        stack<int> s2;
        int ele;
        int num;
        
        //This loop will run until the size of the stack becomes equal to the middle index
        // Ex - stack = 5,4,3,2,1
        while(s.size()!= (sizeOfStack+1)/2){
            ele = s.top();
            s.pop();
            s2.push(ele);
        }
        // s = 3,2,1
        // s2 = 4,5
        s.pop(); // deleting the middle element from the given stack
        // s = 2,1
        // pushing the remaining elements back in stack s.
        while(!s2.empty()){
            num = s2.top();
            s2.pop();
            s.push(num);
        }
        // s = 5,4,2,1
        
        
        return;
    }
};
