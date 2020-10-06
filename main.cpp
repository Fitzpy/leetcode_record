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
    void hanota(vector<int> &A, vector<int> &B, vector<int> &C) {
        int n = A.size();
        solve(n, A, B, C);
    }

    void solve(int n, vector<int> &A, vector<int> &B, vector<int> &C) {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        solve(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        solve(n - 1, B, A, C);
    }
};

int main() {

    return 0;
}