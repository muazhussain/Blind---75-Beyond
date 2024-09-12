// Problem link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Time: O(n^2)
// Space: O(1)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int res = 0;
        for(int i = 0; i < n; i++) {
        	int sum = 0;
        	for(int j = i; j < n; j++) {
        		sum += arr[j];
        		if(sum == 0) {
        			res = max(res, (j - i + 1));
        		}
        	}
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends