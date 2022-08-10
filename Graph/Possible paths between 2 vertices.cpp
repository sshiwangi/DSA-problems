/* Given a Directed Graph having V nodes numbered from 1 to V, and E directed edges. Given two nodes, source and destination, 
count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesn't contain multiple edges, self-loop, and cycles.


Example 1:

Input:
V = 5, E = 7
Edges of Graph = 
{0, 1}
{0, 2}
{0, 4}
{1, 3}
{1, 4}
{2, 4}
{3, 2}
source = 0 
destination = 4

Output: 4
Explanation: 

There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4 */

//code
class Solution {
  public:
  int count = 0;
    void dfs(int src, vector<int> adj[], int dest){
        if(src == dest){
            count++;
            return;
        }
        for(auto it: adj[src]){
             dfs(it,adj,dest);
        }
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        dfs(source,adj,destination);
        return count;
    }
};
