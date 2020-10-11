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
    unordered_map<int, int> mp;

    TreeNode *solve(vector<int> &pre, vector<int> &post, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return NULL;
        TreeNode *head = new TreeNode(pre[L1]);
        if (L1 == R1) return head;
        int pos = mp[pre[L1 + 1]];
        int len = pos - L2 + 1;
        head->left = solve(pre, post, L1 + 1, L1 + len, L2, pos);
        head->right = solve(pre, post, L1 + len + 1, R1, pos + 1, R2 - 1);
        return head;
    }

    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        for (int i = 0; i < n; i++) mp[post[i]] = i;
        return solve(pre, post, 0, n - 1, 0, n - 1);
    }
};

int main() {

    return 0;
}