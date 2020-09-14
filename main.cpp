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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode * cur = root;
        while(cur !=NULL || !st.empty()) {
            while(cur!=NULL){
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur ->right;
            }
            cur = st.top();
            st.pop();
            cur = cur ->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    return 0;
}