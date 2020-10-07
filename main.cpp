#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int depth, vector<int> &nums) {
        if (depth == nums.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[depth]);
        dfs(depth + 1, nums);
        cur.pop_back();
        dfs(depth + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return ans;
    }
};

int main() {

    return 0;
}