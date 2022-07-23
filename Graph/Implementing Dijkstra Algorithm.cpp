/* Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:
V = 2, E = 1
u = 0, v = 1, w = 9
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2). */

//code
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distTo(V+1, INT_MAX);
        distTo[S] = 0; // distance to source from source is 0
        pq.push({0,S});// pushing (distance and source)
        
        while(!pq.empty()){
            // take out the minm distance pair
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            // and go to it's adjacent
            for(auto it: adj[prev]){
                // int next = it.first;
                // int nextDist = it.second;
                // if the distance from source to prev's adjacent is lesser than the existing one, update the distance array
                if(distTo[it[0]]>it[1] + dist){
                    distTo[it[0]]=it[1]+dist;
                    pq.push({it[1]+dist,it[0]}); 
                }
            }
        }
        return distTo;
    }
};
