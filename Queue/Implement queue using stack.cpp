/* WE have to design a queue using stack
   Take 2 stacks named input and output and follow these steps
 For push operation
   1. push(x)
      push x in input stack
   
   2. For pop()
    if output is not empty
       pop the top element and return it
    else
       push input elements in the output stack
       and pop the top element from the output stack/
       
    Time complexity of push operation will be  O(1) and pop operation will be sometimes  O(1) 
    and sometimes  O(n) */
    
class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(input.empty() && output.empty()){
            return -1;
        }
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int ele = output.top();
        output.pop();
        return ele;
    }
};
