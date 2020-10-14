#include <bits/stdc++.h>

using namespace std;

//10,9,2,5,3,7,101,18
class Solution {
public:
    int dp[100010];

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int len = 0;
        dp[len++] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len - 1]) {
                dp[len++] = nums[i];
            } else {
                int pos = lower_bound(dp, dp + len, nums[i]) - dp;
                dp[pos] = nums[i];
            }
        }
        return len;
    }
};

int main() {

    return 0;
}