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
    pair<ListNode *, ListNode *> solve(ListNode *head, ListNode *tail) {
        ListNode *ret = tail->next;
        ListNode *cur = head;
        while (ret != tail) {
            ListNode *temp = head->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode *swapPairs(ListNode *head) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = head, *pre = hair;
        int num = 0;
        while (cur) {
            num++;
            if (num == 2) {
                auto ret = solve(pre->next, cur);
                pre->next = ret.first;
                pre = ret.second;
                cur = ret.second->next;
                num = 0;
            } else {
                cur = cur->next;
            }
        }
        return hair->next;
    }
};

int main() {

    return 0;
}