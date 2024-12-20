// Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	private:
	struct DSU {
		int n;
		vector<int> par, rank;
		DSU(int _n) {
			n = _n;
			par.resize(n + 1);
			rank.resize(n + 1, 0);
			for(int i = 0; i <= n; i++) {
				par[i] = i;
			}
		}
		int find(int i) {
			if(par[i] == i) {
				return i;
			}
			return par[i] = find(par[i]);
		}
		void merge(int u, int v) {
			int pu = find(u);
			int pv = find(v);
			if(pu == pv) {
				return;
			}
			if(rank[pu] < rank[pv]) {
				par[pu] = pv;
			} else if(rank[pu] > rank[pv]) {
				par[pv] = pu;
			} else {
				par[pv] = pu;
				rank[pu]++;
			}
		}
	};

	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
    	vector<pair<int, pair<int, int>>> edges;
    	for(int u = 0; u < V; u++) {
    		for(auto it : adj[u]) {
    			int v = it[0];
    			int w = it[1];
    			edges.push_back({w, {u, v}});
    		}
    	}
    	sort(edges.begin(), edges.end());
    	int mstW = 0;
    	DSU val(V);
    	for(auto it : edges) {
    		int w = it.first;
    		int u = it.second.first;
    		int v = it.second.second;
    		if(val.find(u) != val.find(v)) {
    			mstW += w;
    			val.merge(u, v);
    		}
    	}
    	return mstW;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends