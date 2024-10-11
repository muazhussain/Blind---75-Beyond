// Problem link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Time: O(sum - max) * n
// Space: O(1)

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++


class Solution {
  private:
  	int countStudent(int n, int arr[], long long pages) {
		int students = 1;
		long long currentPage = 0;
		for(int i = 0; i < n; i++) {
			if(currentPage + arr[i] * 1LL <= pages) {
				currentPage += arr[i] * 1LL;
			} else {
				students++;
				currentPage = arr[i];
			}	
		}
		return students;
	}

  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
    	if(m > n) {
    		return -1;
    	}
    	sort(arr, arr + n);
        long long totalPage = 0;
        long long maxPage = 0;
        for(int i = 0; i < n; i++) {
        	totalPage += arr[i] * 1LL;
        	maxPage = max(maxPage, arr[i] * 1LL);
        }
        for(long long pages = maxPage; pages <= totalPage; pages++) {
        	int students = countStudent(n, arr, pages);
        	if(students == m) {
        		return pages;
        	}
        }
        return maxPage;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends