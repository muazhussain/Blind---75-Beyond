// Problem link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Time: O(log(m))
// Space: O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        if(m > n) {
            return kthElement(k, arr2, arr1);
        }
        int l1, l2, r1, r2;
        int low = max(0, k - n), high = min(k, m);
        while(low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
            l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
            r2 = (cut2 == n) ? INT_MAX : arr2[cut2];
            if(l1 <= r2 && l2 <= r1) {
                break;
            } else if(l1 > r2) {
                high = cut1 - 1;
            } else{
                low = cut1 + 1;
            }
        }
        return max(l1, l2);
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends