#include <bits/stdc++.h>
#include <shared_mutex>

using namespace std;
const int maxn = 1e5 + 7;

class myQueue {
public:
    myQueue() {
        head = tail = 0;
    }

    void push(int val) {
        {
            unique_lock<mutex> lock(queueMutex);
            condition.wait(lock, [this] {
                return !((tail + 1) % size == head);
            });
            a[tail++] = val;
        }
    }

    int front() {
        {
            /*
             * vector原理
             * rpc原理
             * map的内存分配原理
            */
            shared_lock<mutex> lock(queueMutex);
            return a[head];
        }
    }

    void pop() {
        {
            shared_lock<mutex> lock(queueMutex);
            head++;
        }
    }

private:
    int size, head, tail;
    int a[maxn];
    mutex queueMutex;
    condition_variable condition;
};

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        head = tail = count = 0;
        num.resize(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == size) return false;
        count++;
        num[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) return false;
        head = (head + 1) % size;
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (count == 0) return -1;
        return num[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (count == 0) return -1;
        return num[(tail - 1 + size) % size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (count == 0) return true;
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (count == size) return true;
        return false;
    }

private:
    int size, head, tail, count;
    vector<int> num;
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *solve(ListNode *head, ListNode *tail) {
        ListNode *ret = tail->next;
        ListNode *cur = head;
        while (ret != tail) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return ret;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = hair->next, *pre = hair, *tail = head;
        int num = 0;
        while (cur) {
            num++;
            if (num == m - 1) {
                pre = cur;
            }
            if (num == n) {
                tail = cur;
            }
            cur = cur->next;
        }
        solve(pre->next, tail);
        pre->next = tail;
        return hair->next;
    }
};

int main() {
    return 0;
}