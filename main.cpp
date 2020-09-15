#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>vis;
        vis.clear();
        int len = s.size();
        int L = 0, R = 0, ans = 0;
        while (R<len) {
            if (!vis[s[R]]) {
                vis[s[R]]++;
                ans = max(ans, R - L + 1);
                R++;
            } else {
                char pos = s[R];
                while (L <= R) {
                    vis[s[L]]--;
                    L++;
                    if (!vis[pos]) break;
                }
            }
            //printf("L = %d R = %d\n", L,R);
        }
       //printf("%d\n", ans);
        return ans;
    }
} solve;

int main() {
    solve.lengthOfLongestSubstring("abcabcbb");
    return 0;
}