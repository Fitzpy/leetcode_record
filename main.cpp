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
    static bool cmp(string &s1, string &s2) {
        return s1 + s2 < s2 + s1;
    }

    string minNumber(vector<int> &nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end(), cmp);
        string ret;
        for (int i = 0; i < ans.size(); i++) {
            ret += ans[i];
        }
        return ret;
    }
};

int main() {
    return 0;
}