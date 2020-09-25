#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int len = nums.size() - 1;
        int low = 0, high = len, ans = -1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            printf("mid = %d\n", mid);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[0] <= nums[mid]) {
                if (nums[mid] > target && nums[0] <= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] <= nums[len]) {
                if (nums[mid] < target && nums[len] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
} solve;

int main() {
    int n = 6, in2 = 0;
    vector<int> in;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        in.push_back(x);
    }
    solve.search(in, in2);
    return 0;
}