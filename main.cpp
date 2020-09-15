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
    int L[100010], R[100010];

    int trap(vector<int> &height) {
        int len = height.size();
        for (int i = 1; i <= len; i++) {
            L[i] = max(L[i - 1], height[i - 1]);
        }
        for (int i = len; i >= 1; i--) {
            R[i] = max(R[i + 1], height[i - 1]);
        }
        int sum = 0;
        for (int i = 1; i <= len; i++) {
            int minn = min(L[i - 1], R[i + 1]);
            if (height[i - 1] < minn) {
                sum += minn - height[i - 1];
            }
        }
        return sum;
    }
};

int main() {

    return 0;
}