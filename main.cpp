#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    int countSubstrings(string s) {
        string cur;
        cur += '$';
        cur += '#';
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cur += s[i];
            cur += '#';
        }
        vector<int> mp(cur.size() + 5, 0);
        int maxlen = 0, res = 0, mx = 0, id = 0;
        for (int i = 0; i < cur.size(); i++) {
            mp[i] = mx >= i ? min(mp[2 * id - i], mx - i) : 1;
            while (cur[i + mp[i]] == cur[i - mp[i]]) mp[i]++;
            if (i + mp[i] > mx) {
                mx = i + mp[i];
                id = i;
            }
            maxlen = max(maxlen, mp[i] - 1);
            res += mp[i] / 2;
        }
        cout<<res<<endl;
        return res;
    }
}solve;

int main() {
    string s = "abc";
    solve.countSubstrings(s);
    return 0;
}