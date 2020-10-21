
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<int> &nums, int mid) {
        int L = 0, R, ret = 0;
        for (R = 0; R < nums.size(); R++) {
            while (nums[R] - nums[L] > mid) L++;
            ret += R - L;
        }
        return ret;
    }

    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back(), ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, mid) > k) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}