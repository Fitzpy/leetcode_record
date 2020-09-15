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
    int majorityElement(vector<int> &nums) {
        int len = nums.size();
        int key = nums[0], num = 1;
        for (int i = 1; i < len; i++) {
            if (num == 0) {
                key = nums[i];
                num = 1;
            } else if (nums[i] != key) {
                num--;
            } else {
                num++;
            }
        }
        return key;
    }
};

int main() {

    return 0;
}