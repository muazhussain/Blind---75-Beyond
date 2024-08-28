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
    	int res = 0, count = 0;
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                i++;
                count++;
                res = max(res, count);
            } else {
                count--;
                j++;
            }
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