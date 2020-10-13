#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    pair<ListNode *, ListNode *> solve(ListNode *head, ListNode *tail) {
        ListNode *cur = head;
        ListNode *ret = tail->next;
        while (cur!=tail) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int num = 0;
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = head, *pre = hair;
        while (cur) {
            num++;
            if (num == k) {
                pair<ListNode *, ListNode *> ret = solve(pre->next, cur);
                printf("%d %d\n",ret.first->val,ret.second->val);
                pre->next = ret.first;
                cur = ret.second->next;
                pre = ret.second;
                num = 0;
            } else {
                cur = cur->next;
            }
        }
        return hair->next;
    }
};

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