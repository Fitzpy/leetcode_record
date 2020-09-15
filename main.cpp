#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0], pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = max(pre+nums[i],nums[i]);
            ans = max(ans,pre);
        }
        return ans;
    }
};

int main() {

    return 0;
}