// Problem link:
// Time: O(V + E)
// Space: O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  	bool detectCycle(int src, vector<int> adj[], vector<bool>& vis) {
  		queue<pair<int, int>> q;
  		q.push({src, -1});
  		vis[src] = true;
  		while(!q.empty()) {
  			int node = q.front().first;
  			int par = q.front().second;
  			q.pop();
  			for(int v : adj[node]) {
  				if(!vis[v]) {
  					q.push({v, node});
  					vis[v] = true;
  				} else if(v != par) {
  					return true;
  				}
  			}
  		}
  		return false;
  	}

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int node = 0; node < V; node++) {
        	if(!vis[node]) {
        		if(detectCycle(node, adj, vis)) {
        			return true	;
        		}
        	}
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends