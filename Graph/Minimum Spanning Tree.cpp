/* Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2). */

//code
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // using prim's algo
        int parent[V], key[V];
        bool mstSet[V];
        
        for(int i = 0; i<V; i++){
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }
        // declare a min heap to find minimum value index in key array
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0,0}); // push key value and index
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            mstSet[u] = true; // if the index is not marked, mark it to be true
            // iterate in its adjacent
            for(auto it: adj[u]){
                // if the adjacent node are not present in mst and it's weight is less than the previous weight in key array
                if(mstSet[it[0]] == false && it[1]<key[it[0]]){
                    parent[it[0]] = u; // storing the parent of this adjacent in the parent array
                    key[it[0]] = it[1]; //update weight in key
                    pq.push({key[it[0]], it[0]});
                    
                }
            }
        }
        int cost = 0;
        for(int i = 0; i<V; i++){
            cost += key[i];
        }
        return cost;
    }
};
