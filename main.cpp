#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> mp;
        while (head != NULL) {
            if (mp.count(head)) {
                return true;
            } else {
                mp[head] = 1;
                head = head->next;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}