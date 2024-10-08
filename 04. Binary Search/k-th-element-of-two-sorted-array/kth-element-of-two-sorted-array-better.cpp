// Problem link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Time: O(m + n)
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
        int cnt = 0;
        int i = 0, j = 0;
        while(i < m && j < n) {
        	if(arr1[i] < arr2[j]) {
                if(cnt == k - 1) {
                    return arr1[i];
                }
        		i++;
        	} else {
                if(cnt == k - 1) {
                    return arr2[j];
                }
        		j++;
        	}
            cnt++;
        }
        while(i < m) {
            if(cnt == k - 1) {
                return arr1[i];
            }
            i++;
            cnt++;
        }
        while(j < n) {
            if(cnt == k - 1) {
                return arr2[j];
            }
            j++;
            cnt++;
        }
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