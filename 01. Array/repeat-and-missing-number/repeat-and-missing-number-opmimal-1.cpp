// Problem link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
        long long n = arr.size();
    	long long sN = (n * (n + 1))	/ 2;
    	long long s2N = (n * (n + 1) * (2 * n + 1))	/ 6;
    	long long s = 0, s2 = 0;
    	for(int e : arr) {
    		s += (long long) e;
    		s2 += (long long) e * (long long) e;
    	}
    	long long val1 = s - sN;
    	long long val2 = s2 - s2N;
    	val2 = val2 / val1;
    	int x = (val1 + val2) / 2;
    	int y = val2 - x;
    	return {x, y};
    }
};