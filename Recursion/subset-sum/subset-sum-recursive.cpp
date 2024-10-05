// Problem link: https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Time: O(2^n + 2^nLog2^n)
// Space: O(2^n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void func(int idx, int sum, vector<int>& arr, vector<int>& subsetSums) {
        if(idx == arr.size()) {
            subsetSums.push_back(sum);
            return;
        }
        func(idx + 1, sum + arr[idx], arr, subsetSums);
        func(idx + 1, sum, arr, subsetSums);
    }

  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> subsetSums;
        func(0, 0, arr, subsetSums);
        sort(subsetSums.begin(), subsetSums.end());
        return subsetSums;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends