#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int len = s.size();
        int l = 0, r = 0, ans = 0;
        while (r < len) {
            if (mp[s[r]] == 1) {
                while (mp[s[r]] == 1) {
                    mp[s[l]]--;
                    l++;
                }
                mp[s[r]] = 1;
            } else {
                mp[s[r]] = 1;
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}