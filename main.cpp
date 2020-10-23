class Solution {
public:
    ListNode *solve(ListNode *head) {
        ListNode *ret = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return ret;
    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *ret = solve(slow->next);
        ListNode *cur = head;
        while (ret) {
            if (ret->val != cur->val) return false;
            ret = ret->next;
            cur = cur->next;
        }
        return true;
    }
};