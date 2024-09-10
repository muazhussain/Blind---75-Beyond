// Problem link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Time: O(n^2)
// Space: O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(vector<long long> &arr) {
        long long res = 0;
        for(int i = 0; i < arr.size() - 1; i++) {
        	for(int j = i + 1; j < arr.size(); j++) {
        		if(arr[i] > arr[j]) {
        			res++;
        		}
        	}
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends