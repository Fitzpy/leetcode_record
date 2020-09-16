#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> deq;
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i < k) {
                if (deq.empty()) deq.push_back(i);
                else {
                    while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
                    deq.push_back(i);
                }
                if (i == k - 1) ans.push_back(nums[deq.front()]);
            } else {
                if (!deq.empty() && i - deq.front() >= k) deq.pop_front();
                if (deq.empty()) deq.push_back(i);
                else {
                    while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
                    deq.push_back(i);
                }
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
} solve;

int main() {
    vector<int> in;
    int k = 3;
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        in.push_back(x);
    }
    solve.maxSlidingWindow(in, k);
    return 0;
}