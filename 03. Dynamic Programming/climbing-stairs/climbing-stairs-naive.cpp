// Problem link: https://leetcode.com/problems/climbing-stairs/
// Time: (2 ^ n)
// Space: O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) {
            return 1;
        }   
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};