// Problem link: https://leetcode.com/problems/valid-parentheses/
// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
        	if(ch == '(' || ch == '{' || ch == '[') {
        		st.push(ch);
        	} else if(st.empty()) {
        		return false;
        	} else {
        		if(ch == ')' && st.top() != '(') {
        			return false;
        		} else if(ch == '}' && st.top() != '{') {
        			return false;
        		} else if(ch == ']' && st.top() != '[') {
        			return false;
        		}
        		st.pop();
        	}
        }
        return st.empty();
    }
};