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
    string longestPalindrome(string s) {
        string cur;
        cur += "$#";
        for (int i = 0; i < s.size(); i++) {
            cur += s[i];
            cur += '#';
        }
        vector<int> mp(cur.size() + 1, 0);
        int maxlen = 0, mx = 0, id = 0, ans = 0;
        for (int i = 1; i < cur.size(); i++) {
            mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
            while (cur[i + mp[i]] == cur[i - mp[i]]) mp[i]++;
            if (mp[i] + i > mx) {
                mx = mp[i] + i;
                id = i;
            }
            if (mp[i] - 1 > maxlen) {
                maxlen = mp[i] - 1;
                ans = i;
            }
        }
        string ret;
        for (int i = ans - mp[ans]+1; i < ans + mp[ans]; i++) {
            if (cur[i] != '#' && cur[i] !='$')  ret += cur[i];
        }
        return ret;
    }
};

int main() {
    string s="babad";
    solve.longestPalindrome(s);
    return 0;
}