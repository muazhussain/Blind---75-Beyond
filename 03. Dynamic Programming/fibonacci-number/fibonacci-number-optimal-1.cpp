// Problem link: https://leetcode.com/problems/fibonacci-number/
// Time: O(n)
// Space: O(n)

class Solution {
private:
    int calc(int n, vector<int>& table) {
        if(table[n] != -1) {
            return table[n];
        } else if(n < 0) {
            return 0;
        }
        else if(n <= 1) {
            return table[n] = n;
        }
        return table[n] = calc(n - 1, table) + calc(n - 2, table);
    }

public:
    int fib(int n) {
        vector<int> table(n + 1, -1);
        return calc(n, table);
    }
};