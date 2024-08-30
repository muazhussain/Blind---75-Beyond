// Problem link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> count(5, 0);
        int res = 0, curr = 0;
        for(char ch : croakOfFrogs) {
            if(ch == 'c') {
                count[0]++;
                curr++;
                res = max(res, curr);
            } else if(ch == 'r') {
                if(count[0] <= count[1]) {
                    return -1;
                }
                count[1]++;
            } else if(ch == 'o') {
                if(count[1] <= count[2]) {
                    return -1;
                }
                count[2]++;
            } else if(ch == 'a') {
                if(count[2] <= count[3]) {
                    return -1;
                }
                count[3]++;
            } else if(ch == 'k') {
                if(count[3] <= count[4]) {
                    return -1;
                }
                count[4]++;
                curr--;
            }
        }
        for(int i = 1; i < 5; i++) {
            if(count[0] != count[i]) {
                return -1;
            }
        }
        return res;
    }
};