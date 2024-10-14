// Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time: O(V + E)
// Space: O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
    	vector<int> indegree(V, 0);
        for(int node = 0; node < V; node++) {
            for(int v : adj[node]) {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int node = 0; node < V; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(int v : adj[node]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count != V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends