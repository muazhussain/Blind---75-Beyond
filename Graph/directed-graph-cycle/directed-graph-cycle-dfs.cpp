// Problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time: O(V + E)
// Space: O(V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  	bool checkCycle(int node, vector<int> adj[],  vector<bool>& nodeVis, vector<bool>& dfsVis) {
  		nodeVis[node] = true;
		dfsVis[node] = true;
  		for(int v : adj[node]) {
  			if(!nodeVis[v]) {
  				if(checkCycle(v, adj, nodeVis, dfsVis)) {
  					return true;
  				}
  			} else if(dfsVis[v]) {
  				return true;
  			}
  		}
		dfsVis[node] = false;
  		return false;
  	}

  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
    	vector<bool> nodeVis(V, false);
    	vector<bool> dfsVis(V, false);
        for(int node = 0; node < V; node++) {
        	if(!nodeVis[node]) {
        		if(checkCycle(node, adj, nodeVis, dfsVis) == true) {
        			return true;
        		}
        	}
        }
        return false;
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