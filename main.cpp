#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        Head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur = Head;
        int num = 0, ret = Head->val;
        while (cur) {
            int now = rand() % (num + 1);
            num++;
            if (now == 0) {
                ret = cur->val;
            }
            cur = cur->next;
        }
        return ret;
    }

private:
    ListNode *Head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main() {
    return 0;
}