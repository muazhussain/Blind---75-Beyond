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
    int maxLen(vector<int>& arr, int n, int k = 0) {
        int res = 0;
        int n = arr.size();
        long long sum = 0;
        int left = 0, right = 0;
        while(right < n) {
            sum += arr[right];
            while(left <= right && sum > k) {
                sum -= arr[left];
                left++;
            }
            if(sum == k) {
                res = max(res, right - left);
            }
            right++;
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