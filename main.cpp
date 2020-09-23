#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = head;
        ListNode *cur = NULL;
        while (pre != NULL) {
            ListNode *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};

int main() {

    return 0;
}
