#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode *, int> mp1, mp2;

    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        mp1[root] = root->val + mp2[root->left] + mp2[root->right];
        mp2[root] = max(mp1[root->left], mp2[root->left]) + max(mp1[root->right], mp2[root->right]);

    }

    int rob(TreeNode *root) {
        mp1.clear();
        mp2.clear();
        dfs(root);
        return max(mp1[root], mp2[root]);
    }
};

int main() {

    return 0;
}
