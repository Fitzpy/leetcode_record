#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

int a[] = {3, 2, 1, 1, 1};

void quick_sort(int L, int R) {
    if (L > R) return;
    int i = L, j = R, val = a[L];
    while (i < j) {
        while (i < j && a[j] >= val) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= val) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = val;
    quick_sort(L, i - 1);
    quick_sort(i + 1, R);
}

int top, heap[100010];

void push(int val) {
    heap[++top] = val;
    int temp = top;
    while (temp > 1) {
        int root = temp / 2;
        if (heap[root] >= val) {
            swap(heap[root], heap[temp]);
            temp = root;
        } else break;
    }
}

int pop() {
    if (top == 0) return 9999999;
    int ret = heap[1];
    heap[1] = heap[top];
    int root = 1;
    while (root * 2 < top) {
        int lson = root * 2, rson = root * 2 + 1;
        if (rson >= top || heap[lson] < heap[rson]) {
            if (heap[lson] <= heap[root]) {
                swap(heap[lson], heap[root]);
                root = lson;
            } else break;
        } else {
            if (heap[rson] <= heap[root]) {
                swap(heap[rson], heap[root]);
                root = rson;
            } else break;
        }
    }
    top--;
    return ret;
}

class ThreadPool {
public:
    ThreadPool(int num);

    template<class F, class ...Args>
    void push(F &&f, Args ...args);

    ~ThreadPool();

private:
    bool stop;
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queue_mutex;
    condition_variable condition;
};

ThreadPool::ThreadPool(int num) : stop(false) {
    for (int i = 0; i < num; i++) {
        workers.emplace_back([this] {
            while (1) {
                function<void()> task;
                {
                    unique_lock<mutex> lock(this->queue_mutex);
                    condition.wait(lock, [this] {
                        return this->stop || !this->tasks.empty();
                    });
                    if (this->stop && this->tasks.empty()) return;
                    task = move(this->tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

template<class F, class ...Args>
void ThreadPool::push(F &&f, Args ...args) {
    auto task = bind(f, args...);
    {
        unique_lock<mutex> lock1(queue_mutex);
        if (stop) return;
        tasks.push(task);
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        unique_lock<mutex> lock1(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (thread &worker:workers) {
        worker.join();
    }
}

void task1(int i) {
    printf("thread = %d i = %d\n", this_thread::get_id(), i);
}

void task2(int i, int j) {
    printf("thread = %d i = %d j = %d\n", this_thread::get_id(), i, j);
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getNode(ListNode *head, int num) {
        if (head == NULL) return NULL;
        ListNode *cur = head;
        while (--num && cur) {
            cur = cur->next;
        }
        if (cur == NULL) return cur;
        ListNode *ret = cur->next;
        cur->next = NULL;
        return ret;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return ret->next;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *cur = head;
        int num = 0;
        while (cur) {
            num++;
            cur = cur->next;
        }
        for (int i = 1; i < num; i *= 2) {
            cur = ret->next;
            ListNode *tail = ret;
            while (cur) {
                ListNode *left = cur;
                ListNode *right = getNode(left, i);
                cur = getNode(right, i);
                tail->next = merge(left, right);
                while (tail->next) tail = tail->next;
            }
        }
        return ret->next;
    }
};


int main() {

    return 0;
}