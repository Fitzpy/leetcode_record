#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        multiset<int> st;
        for (int i = 0; i < k; i++) st.insert(nums[i]);
        multiset<int>::iterator it = next(st.begin(), k / 2);
        vector<double> ret;
        for (int i = k;; i++) {
            ret.push_back((1.0 * (*it) + *(next(it, k % 2 - 1))) * 0.5);
            if (i == nums.size()) break;
            st.insert(nums[i]);
            if (nums[i] < (*it)) it--;
            if (nums[i - k] <= (*it)) it++;
            st.erase(st.lower_bound(nums[i - k]));
        }
        return ret;
    }
} solve;

int main() {
    vector<int> in;
    int n = 8, k = 3;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        in.push_back(x);
    }
    solve.medianSlidingWindow(in, k);
    return 0;
}