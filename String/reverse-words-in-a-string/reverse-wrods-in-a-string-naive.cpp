// Problem link: https://leetcode.com/problems/reverse-words-in-a-string/
// Time: O(len)
// Space: O(len)

class Solution {
public:
    string reverseWords(string s) {
    	s += ' ';
    	string curr = "";
    	stack<string> st;
    	for(char ch : s) {
    		if(ch == ' ') {
    			if(curr.empty()) {
    				continue;
    			}
    			st.push(curr);
    			curr = "";
    		} else {
    			curr += ch;
    		}
    	}
    	string res = "";
    	while(!st.empty()) {
    		res += st.top();
    		if(st.size() > 1) {
    			res += " ";
    		}
    		st.pop();
    	}
    	return res;
    }
};