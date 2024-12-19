// Problem link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        int v = adj.size();
        const int inf = 1e9;
        vector<int> dist(v, inf);
        dist[src] = 0;
        while(!pq.empty()) {
        	auto it = pq.top();
        	pq.pop();
        	int u = it.second;
        	int d = it.first;
        	for(auto p : adj[u]) {
        		if(d + p.second < dist[p.first]) {
        			dist[p.first] = d + p.second;
        			pq.push({dist[p.first], p.first});
        		}
        	}
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends