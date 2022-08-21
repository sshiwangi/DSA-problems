/* There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first 
finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. 
Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.

Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible order is [0, 1]. 

Your Task:
The task is to complete the function findOrder() which takes two integers n, and m and a list of lists of size m*2 denoting the prerequisite pairs as input and 
returns any correct order to finish all the tasks. Return an empty array if it's impossible to finish all tasks.

Constraints:
1 ≤ n ≤ 104
0 ≤ m ≤ 105
0 ≤ prerequisites[0], prerequisites[1] ≤ 105
All prerequisite pairs are unique
prerequisites[0] ≠ prerequisites[1] */

//code
class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        // topological sort
        int count = 0; // maintain a count variable that will store the no. of nodes pushed in the queue
        queue<int>q;
        vector<int>indegree(n,0);
        vector<vector<int>> adj(n,vector<int>());
        // storing indegree of nodes
        for(vector<int>v: prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        vector<int>ans;
        vector<bool>visited(n,false);
        for(int i = 0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
                visited[i] = true;
                count++;
            }
        }
        //bfs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //visit its neighbours
            
            vector<int>neighbours = adj[node];
            for(int neighbour: neighbours){
                if(!visited[neighbour]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                        ans.push_back(neighbour);
                        visited[neighbour] = true;
                        count++;
                    }
                }
            }
        }
        // if the graph has a cycle, it will not return any order.
        if(count!=n)return {};
        return ans;
    }
};
