// Problem link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Time: O(m + n)
// Space: O(m + n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        vector<int> temp(m + n);
        int i = 0, j = 0, idx = 0;
        while(i < m && j < n) {
        	if(arr1[i] < arr2[j]) {
        		temp[idx] = arr1[i];
        		i++;
        	} else {
        		temp[idx] = arr2[j];
        		j++;
        	}
        	idx++;
        }
        while(i < m) {
        	temp[idx] = arr1[i];
        	i++;
        	idx++;
        }
        while(j < n) {
        	temp[idx] = arr2[j];
        	j++;
        	idx++;
        }
        return temp[k - 1];
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