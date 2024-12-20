// Problem link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int v = mat.size();
        for(int i = 0; i < v; i++) {
        	for(int j = 0; j < v; j++) {
        		if(mat[i][j] == -1) {
        			mat[i][j] = INT_MAX;
        		}
        		if(i == j) {
        			mat[i][j] = 0;
        		}
        	}
        }

        for(int j = 0; j < v; j++) {
        	for(int i = 0; i < v; i++) {
        		for(int k = 0; k < v; k++) {
        			mat[i][k] = min(mat[i][k], mat[i][j] + mat[j][k]);
        		}
        	}
        }
			
        for(int i = 0; i < v; i++) {
        	for(int j = 0; j < v; j++) {
        		if(mat[i][j] == INT_MAX) {
        			mat[i][j] = -1;
        		}
        	}
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends