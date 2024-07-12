// Problem link: https://leetcode.com/problems/unique-paths/
// Time complexity: O(2^(m + n))
// Space complexity: O(m + n)

class Solution {
private:
    int countPaths(int r, int c, int i, int j) {
        if(i >= r || j >= c) return 0;
        if(i == r - 1 && j == c - 1) return 1;
        return countPaths(r, c, i, j + 1) + countPaths(r, c, i + 1, j);
    }
public:
    int uniquePaths(int m, int n) {
        return countPaths(m, n, 0, 0);
    }
};