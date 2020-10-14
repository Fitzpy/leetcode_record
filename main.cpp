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
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                int pos = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && (s1[i - 1] == s3[pos]));
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && (s2[j - 1] == s3[pos]));
                }
            }
        }
        return bool(dp[len1][len2]);
    }
};

int main() {

    return 0;
}