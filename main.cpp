#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *now1 = head, *now2 = head;
        int num = 0;
        while (now2 != NULL) {
            num++;
            if (num < k) {
                now2 = now2->next;
            } else {
                now1 = now1->next;
                now2 = now2->next;
            }
        }
        return now1;
    }
};

int main() {
    return 0;
}