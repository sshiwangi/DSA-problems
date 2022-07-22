/* Given the adjacency list of a bidirectional graph. Your task is to copy/clone the adjacency list for each vertex and return a new list.
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V + E) */

//code
class Solution
{
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> ans;
        // iterate in vertex
        for(int i = 0; i<V; i++){
            vector<int> adjNodes;
            // push the vertex in adjNodes vector and iterate across its adjacents
            adjNodes.push_back(i);
            for(auto it: adj[i]){
                adjNodes.push_back(it);
            }
            ans.push_back(adjNodes);
        }
        // return the new list of vectors
        return ans;
    }
};
