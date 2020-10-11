#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!st.empty())st.pop();
        while (!st1.empty()) st1.pop();
    }

    void push(int x) {
        st.push(x);
        if (st1.empty()) st1.push(x);
        else {
            st1.push(min(st1.top(), x));
        }
    }

    void pop() {
        st.pop();
        st1.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st1.top();
    }

private:
    stack<int> st;
    stack<int> st1;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();  // --> ·µ»Ø -3.
    minStack.pop();
    minStack.top();     // --> ·µ»Ø 0.
    minStack.getMin();  // --> ·µ»Ø -2.

    return 0;
}