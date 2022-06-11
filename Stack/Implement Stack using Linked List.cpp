/*
Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

Example 1:

Input: 
push(2)
push(3)
pop()
push(4) 
pop()
Output: 3 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4 */

//Function to push an integer into the stack.

void MyStack ::push(int x) 
{
    // Your Code
    // top is head here which is given to be null
    // so create a node and make the next of it point to top that is null
    StackNode* temp;
    temp = new StackNode(x);
    temp->next = top;
    top = temp; // temp will be new head
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    StackNode* del;
    
    if(top == NULL){
        return -1;
    }
    int ans = top->data;
    del = top;
    top = top->next;
    delete del;
    return ans;
}
