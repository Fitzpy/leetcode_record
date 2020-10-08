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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                } else {
                    dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                }
                //ret = max(ret, dp[i][j]);
            }
        }
        return dp[n][m];
    }
};

int main() {

    return 0;
}