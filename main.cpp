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
    vector<string> ret;

    void dfs(TreeNode *root, string s) {
        if (root != nullptr) {
            s += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                ret.push_back(s);
            }else {
                s += "->";
                dfs(root->left,s);
                dfs(root->right,s);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        ret.clear();
        dfs(root,"");
        return ret;
    }
};


int main() {
    return 0;
}