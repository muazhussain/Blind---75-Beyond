// Problem link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Time: O(3^(n^2))
// Space: O(length_of_path * number_of_path)

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
  	bool isValidCell(int row, int col, int n, int m) {
  		return row >= 0 && row < n && col >= 0 && col < m;
  	}

  	void solve(int row, int col, int n, int m, string current, vector<pair<char, pair<int, int>>>& dirs, vector<vector<bool>>& visited, vector<vector<int>>& mat, vector<string>& res) {
  		if(row == n - 1 && col == m - 1) {
  			res.push_back(current);
  			return;
  		}
  		for(auto dir : dirs) {
  			int r = row + dir.second.first;
  			int c = col + dir.second.second;
  			if(isValidCell(r, c, n, m) && !visited[r][c] && mat[r][c] != 0) {
  				current.push_back(dir.first);
  				visited[r][c] = true;
  				solve(r, c, n, m, current, dirs, visited, mat, res);
  				current.pop_back();
  				visited[r][c] = false;
  			}
  		}
  	}

  public:
    vector<string> findPath(vector<vector<int>> &mat) {
    	int n = mat.size();
    	int m = mat[0].size();
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<char, pair<int, int>>> dirs = {{'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}};
        if(mat[0][0] == 0) {
    		return res;
    	}
    	visited[0][0] = true;
        solve(0, 0, n, m, "", dirs, visited, mat, res);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends