// Problem link: https://leetcode.com/problems/implement-queue-using-stacks/
// Time: Push -> O(n), Everything else -> O(1)
// Space: O(n)

class MyQueue {
private:
    stack<int> st, helper;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()) {
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */