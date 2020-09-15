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
    int maxArea(vector<int> &height) {
        int low = 0, high = height.size() - 1;
        int ans = 0;
        while (low < high) {
            ans = max(ans, min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}