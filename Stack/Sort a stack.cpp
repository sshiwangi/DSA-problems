/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2 */
// using recursion
void insert(stack<int> &s, int ele){
    if(s.empty() || s.top()<=ele && !s.empty()){
        s.push(ele);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,ele);
    s.push(val);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==1){
       return;
   }
   int ele = s.top();
   s.pop();
   sort();
   insert(s,ele);
   return;
}
