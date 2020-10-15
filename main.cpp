#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        vector<int> ret;
        if (nums.size() == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("low = %d\n", low);
        if (low == nums.size() || nums[low] != target) low = -1;
        ret.push_back(low);
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high < 0 || nums[high] != target) high = -1;
        ret.push_back(high);
        return ret;
    }
};

int main() {

    return 0;
}