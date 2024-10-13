// Problem link: https://www.naukri.com/code360/problems/next-smaller-element_1112581
// Time: O(n^2)
// Space: O(n)

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    for(int i = 0; i < n; i++) {
    	for(int j = i + 1; j < n; j++) {
    		if(arr[j] < arr[i]) {
    			nse[i] = arr[j];
    			break;
    		}
    	}
    }
    return nse;
}