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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ret;
        if (root == NULL) return ret;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *now = que.front();
            que.pop();
            if (now != NULL) {
                ret += to_string(now->val);
                que.push(now->left);
                que.push(now->right);
            } else ret += "null";
            ret += ',';
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() <= 2) return NULL;
        vector<string> cur;
        int len = 0, n = data.size();
        for (int i = 0; i < n; i++) {
            if (data[i] == ',') {
                cur.push_back(data.substr(i - len, len));
                len = 0;
            } else len++;
        }
        if (cur[0] == "null") return NULL;
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(stoi(cur[0]));
        TreeNode *temp = root;
        que.push(temp);
        int idx = 0;
        while (!que.empty()) {
            TreeNode *now = que.front();
            que.pop();
            if (++idx >= cur.size()) break;
            if (cur[idx] != "null") {
                now->left = new TreeNode(stoi(cur[idx]));
                que.push(now->left);
            }
            if (++idx >= cur.size()) break;
            if (cur[idx] != "null") {
                now->right = new TreeNode(stoi(cur[idx]));
                que.push(now->right);
            }
        }
        return root;
    }
};

int main() {

    return 0;
}