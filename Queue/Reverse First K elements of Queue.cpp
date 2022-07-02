/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n) */

// code

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> st;
    stack<int> s;
    /* steps
    1. take out all elements from queue and store it in stack st
    2. take out all elements from st except those k elements which needs to be reversed and store
       it in another stack s
    3. now remove the elements one by one first from st and then from s and push back in the queue*/
    
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }
    
    while(st.size() != k){
        int ele1 = st.top();
        st.pop();
        s.push(ele1);
    }
    while(!st.empty()){
        int ele2 = st.top();
        st.pop();
        q.push(ele2);
    }
    
    while(!s.empty()){
        int ele3 = s.top();
        s.pop();
        q.push(ele3);
    }
    return q;
}
