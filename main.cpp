#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        v = nums;
        ans = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = v;
        return ans;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = ans.size();
        for (int i=0 ;i<len ;i++){
            int idx = rand()%(i+1);
            swap(ans[i],ans[idx]);
        }
        return ans;
    }

private:
    vector<int>v;
    vector<int>ans;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    return 0;
}