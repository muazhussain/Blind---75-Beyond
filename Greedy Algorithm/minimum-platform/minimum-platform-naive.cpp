// Problem link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Time: O(n^2)
// Space: O(1)

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int res = 0;
    	for(int i = 0; i < n - 1; i++) {
    		int curr_max = 1;
    		for(int j = i + 1; j < n; j++) {
    			if ((arr[i] <= dep[j] && arr[i] >= arr[j]) || (arr[j] <= dep[i] && arr[j] >= arr[i])) {
                	curr_max++;
            	}	
    		}
    		res = max(res, curr_max);
    	}
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends