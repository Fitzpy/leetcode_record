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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *cur = root;
        while (cur != NULL && !st.empty()) {
            while (cur != NULL) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return ans;
    }
};

int main() {
    return 0;
}