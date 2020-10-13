#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int pos = nums.size() - 2;
        while (pos >= 0 && nums[pos + 1] <= nums[pos]) pos--;
        if (pos >= 0) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[pos]) {
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
        }
        reverse(next(nums.begin(), pos + 1), nums.end());
    }
};

int main() {

    return 0;
}