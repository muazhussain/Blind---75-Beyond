// Problem link: https://leetcode.com/problems/longest-palindromic-substring/
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++) {
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;                
            }
            if(res.size() < right - left - 1) {
                res = s.substr(left + 1, right - left - 1);
            }
            left = i, right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;                
            }
            if(res.size() < right - left - 1) {
                res = s.substr(left + 1, right - left - 1);
            }
        }
        return res;
    }
};