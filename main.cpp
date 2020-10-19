#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while (curA != curB) {
            curA = curA != NULL ? curA->next : headB;
            curB = curB != NULL ? curB->next : headA;
        }
        return curA;
    }
};

int main() {

    return 0;
}