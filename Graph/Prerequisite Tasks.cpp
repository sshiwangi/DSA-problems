/* There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, 
which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}

Output:
Yes

Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.

Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}

Output:
No

Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.

Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)


Constraints:
1 ≤ N ≤ 104
1 ≤ P ≤ 105 */

//code

class Solution {
public:
    // Function to check cycle in a directed graph
    bool checkCycle(int node, unordered_map<int,list<int>>& adj, int vis[], int dfsvis[]){
        vis[node] = 1; // mark it in visited array
        dfsvis[node] = 1; // and mark it in dfsvisited array
        
        for(auto it: adj[node]){ // check its adjacent node
            if(!vis[it]){ // if not visited
                if(checkCycle(it,adj,vis,dfsvis)) return true;
                
            }
            // if its mark in visited array and also marked in dfsvis then return true
            else if(dfsvis[it]){
                return true;
            }
        }
        // the node and it's adjacent doesnot return true, return and while returning unmark dfsvis array
        dfsvis[node] = 0;
        return false;
    }
        
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    // creating an adjacency list
	    unordered_map<int,list<int>>adj;
	    for(int i=0;i<prerequisites.size();i++){
	         int u=prerequisites[i].first;
	         int v=prerequisites[i].second;
	         
	         adj[u].push_back(v);
	    }
	     // we only need to check if the graph has cycel or not, if it has cycle, the task won't be completed
	    int vis[N], dfsvis[N];
        memset(vis,0,sizeof vis);
        memset(dfsvis,0,sizeof dfsvis);
        
        for(int i = 0; i<N; i++){
            if(!vis[i]){ // if the node is not visited
                if(checkCycle(i,adj,vis,dfsvis)){
                    return false;
                }
            }
        }
        return true;
	}
};
