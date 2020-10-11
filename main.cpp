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
    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        return max(L, R) + 1;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        int dep = depth(root);
        vector<vector<int>> ret(dep);
        if (root == NULL) return ret;
        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            pair<TreeNode *, int> now = que.front();
            que.pop();
            ret[now.second].push_back(now.first->val);
            if (now.first->left != NULL) que.push(make_pair(now.first->left, now.second + 1));
            if (now.first->right != NULL) que.push(make_pair(now.first->right, now.second + 1));
        }
        return ret;
    }
};

int main() {

    return 0;
}