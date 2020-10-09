#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

class Solution {
public:
    bool check(string s) {
        if (s.size() == 1) {
            return true;
        } else {
            if (s[0] == '0') return false;
            int num = 0;
            for (char i : s) {
                if (i >= '0' && i <= '9') num = num * 10 + i - '0';
                else return false;
                if (num > 255) return false;
            }
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string s1 = s.substr(0, i + 1);
            if (!check(s1)) continue;
            for (int j = i + 1; j < n; j++) {
                string s2 = s.substr(i + 1, j - i);
                if (!check(s2)) continue;
                for (int k = j + 1; k < n; k++) {
                    string s3 = s.substr(j + 1, k - j);
                    if (!check(s3)) continue;
                    string s4 = s.substr(k + 1, n - k);
                    if (!check(s3)) continue;
                    ret.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
            }
        }
        return ret;
    }
};

int main() {

    return 0;
}