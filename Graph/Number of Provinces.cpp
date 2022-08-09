/* Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:
Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. 
City 2 has no path to city 1 or city 3 hence it belongs to another province. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj as 
input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V ≤ 500 */
//code
class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adjList){
        vis[node] = 1;
        for(auto it: adjList[node]){
            if(!vis[it]){
                dfs(it,vis,adjList);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //creating an adjacency list and storing the adj nodes in it.
        vector<vector<int>> adjList(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if( i!=j && adj[i][j]==1){
                     
                    adjList[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<int> vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,adjList);
                count++;
            }
        }
        return count;
    }
};
