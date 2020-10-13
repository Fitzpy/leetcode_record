#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') dp[i + 1] += dp[i];
            if (i > 0 && s[i - 1] != '0') {
                int num = (s[i] - '0') + (s[i - 1] - '0') * 10;
                if (num <= 26 && num > 0) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[n];
    }
};

int main() {

    return 0;
}