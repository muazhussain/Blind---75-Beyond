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
        long long int res = mergeSort(arr, 0, arr.size() - 1);
        return res;
    }

    long long int mergeSort(vector<long long>& arr, int left, int right) {
        if(left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        long long int count = 0;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
        return count;
    }

    int merge(vector<long long>& arr, int left, int mid, int right) {
        vector<long long> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        long long int count = 0;
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++]; 
            } else {
                count += (mid - i + 1LL);
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= right) {
            temp[k++] = arr[j++];
        }
        for(k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
        return count;
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