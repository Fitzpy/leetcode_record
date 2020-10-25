#include <iostream>
#include <thread>
#include <atomic>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class LinkNode {
public:
    T data;
    LinkNode<T> *next;
};

template<class T>
class LockFreeQueue {
public:
    LockFreeQueue<T>() : head_(nullptr), tail_(nullptr), len(0) {
        LinkNode<T> *now = new LinkNode<T>;
        now->next = nullptr;
        head_ = tail_ = now;
    }

    void push(const T &data);

    T pop_front();

    bool empty();

private:
    LinkNode<T> *head_;
    LinkNode<T> *tail_;
    std::atomic_int len;
};

template<class T>
void LockFreeQueue<T>::push(const T &data) {
    LinkNode<T> *now = new LinkNode<T>;
    now->data = data;
    now->next = nullptr;
    LinkNode<T> *p1, *nxt;
    while (1) {
        p1 = tail_;
        nxt = tail_->next;
        if (p1 != tail_) continue;
        if (nxt != nullptr) {
            __sync_bool_compare_and_swap(&tail_, p1, nxt);
            continue;
        }
        if (__sync_bool_compare_and_swap(&tail_->next, nxt, now) == 1) {
            break;
        }
    }
    __sync_bool_compare_and_swap(&tail_, p1, now);
    len++;
}

template<class T>
T LockFreeQueue<T>::pop_front() {
    LinkNode<T> *p1;
    do {
        p1 = head_->next;
        if (p1 == nullptr) {
            return -999999;
        }
    } while (__sync_bool_compare_and_swap(&head_->next, p1, p1->next) != true);
    len--;
    return p1->data;
}

template<class T>
bool LockFreeQueue<T>::empty() {
    return len == 0;
}

LockFreeQueue<int> myQueue;

void func1(void) {
    for (int i = 0; i < 10; i++) {
        myQueue.push(i);
    }
}

void func2(void) {
    for (int i = 30; i < 40; i++) {
        myQueue.push(i);
    }
}

void func3(void) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", myQueue.pop_front());
    }
}

class Solution {
public:
    struct node {
        int val;
        node *lson, *rson;

        node(int val) : val(val), lson(NULL), rson(NULL) {}
    };

    unordered_map<int, int> mp;

    node *build(vector<int> &inorder, vector<int> &postorder, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return NULL;
        int pos = mp[postorder[R2]];
        if (pos > R1 || pos < L1) return NULL;
        node *head = new node(postorder[R2]);
        head->lson = build(inorder, postorder, L1, pos - 1, L2, L2 + pos - L1 - 1);
        head->rson = build(inorder, postorder, pos + 1, R1, L2 + pos - L1, R2 - 1);
        return head;
    }

    bool check(node *head) {
        if (head == NULL) return true;
        node *cur = head;
        if (cur->lson) {
            if (cur->lson->val > head->val) return false;
        }
        if (cur->rson) {
            if (cur->rson->val < head->val) return false;
        }
        bool ret = (check(cur->lson) && check(cur->rson));
        return ret;
    }

    int getNum(node *head) {
        if (head == NULL) return 0;
        return getNum(head->lson) + 1 + getNum(head->rson);
    }

    bool verifyPostorder(vector<int> &postorder) {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        mp.clear();
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        node *head = build(inorder, postorder, 0, n - 1, 0, n - 1);
        int num = getNum(head);
        if (num != n) return false;
        return check(head);
    }
};

int main(int argc, char **argv) {

    return 0;
}