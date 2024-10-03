// Problem link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Time: O(nlogn)
// Space: O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, [] (const Item a, Item b) {
            return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight);
        });
        double res = 0;
        for(int i = 0; i < n; i++) {
            int take = min(w, arr[i].weight);
            res += (take * (arr[i].value * 1.0 / arr[i].weight));
            w -= take;
            if(w == 0) {
                break;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends