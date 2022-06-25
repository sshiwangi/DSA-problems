/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
// Steps
 /* Take 2 queues
 1. For push operation
    push(x)
       push x in q2
       Transfer all elements from q1 to q2 
       swap q1 and q2
 2. For pop operation
       pop()
       pop the element from q1
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty()){
            return -1;
        }
        int ele = q1.front();
        q1.pop();
        return ele;
}
