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
        ListNode *cur = NULL;
        ListNode *now = head;
        while (now != NULL) {
            ListNode *temp = now->next;
            now->next = cur;
            cur = now;
            now = temp;
        }
        return cur;
    }
};

int main() {

    return 0;
}