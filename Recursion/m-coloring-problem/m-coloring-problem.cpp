// Problem link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// Time: O(n^m)
// Space: O(n * n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  	bool isSafe(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
  		for(int v : graph[node]) {
  			if(color[v] == col) {
  				return false;
  			}
  		}	
  		return true;
  	}

  	bool solve(int node, int n, int m, vector<vector<int>>& graph, vector<int>& color) {
  		if(node == n) {
  			return true;
  		}
  		for(int i = 1; i <= m; i++) {
  			if(isSafe(node, i, graph, color) == true) {
  				color[node] = i;
  				if(solve(node + 1, n, m, graph, color) == true) {
  					return true;
  				}
  				color[node] = 0;
  			}
  		}
  		return false;
  	}

  public:
    bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
        vector<int> color(n);
        vector<vector<int>> graph(n);
        for(auto pair : edges) {
        	graph[pair.first].push_back(pair.second);
        	graph[pair.second].push_back(pair.first);
        }
        return solve(0, n, m, graph, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count / 2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false") << endl; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends