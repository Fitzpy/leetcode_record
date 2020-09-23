#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < m; i++) {
            if (i == 0) dp[0][i] = grid[0][i];
            else dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main() {

    return 0;
}
