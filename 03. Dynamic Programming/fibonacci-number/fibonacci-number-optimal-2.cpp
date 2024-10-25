// Problem link: https://leetcode.com/problems/fibonacci-number/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int fib(int n) {
        int prev = 0, curr = 1;
        for(int i = 1; i <= n; i++) {
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};