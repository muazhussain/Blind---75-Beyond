// Problem link: https://leetcode.com/problems/powx-n/
// Time: O(log(n))
// Space: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long double res = 1;
        int pow = abs(n);
        while(pow) {
            if(pow & 1) {
                res *= x;
            }
            x *= x;
            pow >>= 1;
        }
        if(n < 0) {
            res = 1 / res;
        }
        return (double) res;
    }
};