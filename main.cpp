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

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (abs(depth(root->left)-depth(root->right))>1) return false;
        else return (isBalanced(root->left)&isBalanced(root->right));
    }
};

int main() {

    return 0;
}