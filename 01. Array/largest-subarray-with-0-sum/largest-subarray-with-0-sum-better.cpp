// Problem link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Time: O(n)
// Space: O(n)

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
        int sum = 0;
        int k = 0;
        unordered_map<int, int> lookup;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == 0) {
                res = i + 1;
            } else if(lookup.find(sum) != lookup.end()) {
                res = max(res, (i - lookup[sum]));
            } else {
                lookup[sum] = i;            
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