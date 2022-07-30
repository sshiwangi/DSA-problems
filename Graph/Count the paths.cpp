/*
Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.
There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

Example:

Input: edges = {{0,1},{0,3},{1,2},{3,2}}, 
n = 4, s = 0, d = 2
Output: 2
Explanation: There are two ways to reach at 
2 from 0. These are-
1. 0->1->2
2. 0->3->2

Expected Time Compelxity: O(2n)
Expected Space Complexity: O(n+e)

where e is the number of edges in the graph. */

//code
class Solution{
public:
    void dfs(vector<int> adj[], int s, int d, vector<int>&vis, int& count){
        // if the source and distance become equal
        if(s==d){
            count++;
            return;
        }
        vis[s] =1;
        //traverse in its adjacent
        for(auto it: adj[s]){
            if(!vis[it]){
                dfs(adj,it,d,vis,count);
            }
        }
        // after the dfs traversal of a node is over, mark the node to be not visited while returning
        vis[s] = 0;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    //storing the graph in adjacency matrix
	    int count = 0;
	    vector<int> adj[n];
	    for(int i = 0; i<edges.size(); i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
	    //initializing the visited array
	    vector<int> vis(n,0);
	    dfs(adj,s,d,vis,count);
	    return count;
	}
};
