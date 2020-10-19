#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 2, 3, 5, 6, 7, 9, 11};
int L[105], R[105];
int n = 8;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        n *= 2;
        vector<int> L(n + 1, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) st.push(i);
            else {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    L[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            L[st.top()] = -1;
            st.pop();
        }
        vector<int> ret;
        for (int i = 0; i < n / 2; i++) ret.push_back(L[i]);
        return ret;
    }
};

int main() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] <= a[i]) {
                L[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        L[st.top()] = 999999;
        st.pop();
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
    return 0;
}