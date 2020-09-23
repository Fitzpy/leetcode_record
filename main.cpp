#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        priority_queue<int> que;
        for (int i = 0; i < arr.size(); i++) {
            if (que.size() < k) {
                que.push(arr[i]);
            } else {
                que.push(arr[i]);
                que.pop();
            }
        }
        vector<int> ret;
        while (!que.empty()) {
            ret.push_back(que.top());
            que.pop();
        }
        return ret;
    }
};

int main() {

    return 0;
}
