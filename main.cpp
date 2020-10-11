#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(make_pair(s[i], 1));
            } else {
                if (st.top().first == s[i]) {
                    if (st.top().second == k - 1) {
                        while (!st.empty() && st.top().first == s[i]) st.pop();
                    } else st.push(make_pair(s[i], st.top().second + 1));
                } else {
                    st.push(make_pair(s[i], 1));
                }
            }
        }
        string ret;
        while (!st.empty()) {
            ret += st.top().first;
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {

    return 0;
}