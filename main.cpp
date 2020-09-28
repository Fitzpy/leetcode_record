#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if (s[i] == ')') {
                    if (st.top() != '(') return false;
                    else st.pop();
                }
                if (s[i] == '}') {
                    if (st.top() != '{') return false;
                    else st.pop();
                }
                if (s[i] == ']') {
                    if (st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

int main() {

    return 0;
}
