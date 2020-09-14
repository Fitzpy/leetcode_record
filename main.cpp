#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = NULL, *pre = head;
        while(pre!=NULL) {
            ListNode * now = pre->next;
            pre->next = cur;
            cur = pre;
            pre = now;
        }
        return cur;
    }
};

int main() {
    return 0;
}