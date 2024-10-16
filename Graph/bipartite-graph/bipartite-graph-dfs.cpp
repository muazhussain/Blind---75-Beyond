// Problem link: https://leetcode.com/problems/is-graph-bipartite/
// Time: O(V + E)
// Space: O(V)

class Solution {
private:
	bool dfs(vector<vector<int>>& graph, int node, vector<int>& color) {
		for(int v : graph[node]) {
			if(color[v] == -1) {
				color[v] = !color[node];
				if(dfs(graph, v, color) == false) {
					return false;
				}
			} else if(color[v] == color[node]) {
				return false;
			}
		}	
		return true;
	}

public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int n = graph.size();
    	vector<int> color(n, -1);
    	for(int node = 0; node < n; node++) {
    		if(color[node] == -1) {
    			if(dfs(graph, node, color) == false) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
};