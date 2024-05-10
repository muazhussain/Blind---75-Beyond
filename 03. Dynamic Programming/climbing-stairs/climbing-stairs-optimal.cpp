// Problem link: https://leetcode.com/problems/climbing-stairs/
// Time: (n)
// Space: O(1)

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 1;
        for(int i = 2; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        } 
        return curr;
    }
};