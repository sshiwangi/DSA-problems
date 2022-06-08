/*
Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

Example 1:

Input: 
push(2)
push(3)
pop()
push(4) 
pop()
Output: 3, 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4 */

//Function to push an integer into the stack.
stack<int> st;
void MyStack :: push(int x)
{
    // Your Code
    // top is the iterator so while pushing an element move top a step ahead as it is pointing
    // at nowhere (-1) and then put x in that position of the array
    top++;
    arr[top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    // Your Code
    // if the top pointer is -1 then the array has no element so return -1
    if(top == -1){
        return -1;
    }
    // otherwise return the top element
    int x = arr[top];
    top--;
    return x;
    
    
}
