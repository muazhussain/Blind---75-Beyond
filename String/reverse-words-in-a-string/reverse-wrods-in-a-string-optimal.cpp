// Problem link: https://leetcode.com/problems/reverse-words-in-a-string/
// Time: O(len)
// Space: O(1)

class Solution {
public:
    string reverseWords(string s) {
    	s += ' ';
    	string curr = "", res = "";
        for(char ch : s) {
            if(ch == ' ') {
                if(curr.empty()) {
                    continue;
                }
                if(!res.empty()) {
                    res = curr + " " + res;
                } else {
                    res = curr;
                }
                curr = "";
            } else {
                curr += ch;
            }
        }
    	return res;
    }
};