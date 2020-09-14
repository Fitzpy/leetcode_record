#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> ans;
        stack<TreeNode *> st;
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};

int main() {
    return 0;
}