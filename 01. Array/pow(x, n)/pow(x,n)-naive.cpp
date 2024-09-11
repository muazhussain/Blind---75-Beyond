// Problem link: https://leetcode.com/problems/powx-n/
// Time: O(n)
// Space: O(1)

// TLE Solution

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        for(int i = 1; i <= abs(n); i++) {
        	res *= x;
        }
        if(n < 0) {
        	res = 1.0 / res;
        }
        return res;
    }
};