#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class HashMap {
public:
    void put(string s);

    int get(string s);

private:

};

void HashMap::put(string s) {

}

int HashMap::get(string s) {

}


class ThreadPool {
public:
    ThreadPool(int threads);

    template<class F, class ...Args>
    void push(F &&f, Args &&...args);

    ~ThreadPool();

private:
    bool stop;
    mutex queue_mutex;
    condition_variable condition;
    vector<thread> workers;
    queue<function<void()>> tasks;
};

ThreadPool::ThreadPool(int threads) : stop(false) {
    for (int i = 0; i < threads; i++) {
        workers.emplace_back(
                [this] {
                    while (1) {
                        function<void()> task;
                        {
                            unique_lock<mutex> lock(this->queue_mutex);
                            condition.wait(lock, [this] {
                                return this->stop || !this->tasks.empty();
                            });
                            if (this->stop && this->tasks.empty()) return;
                            task = move(tasks.front());
                            tasks.pop();
                        }
                        task();
                    }
                }
        );
    }
}

template<class F, class ...Args>
void ThreadPool::push(F &&f, Args &&...args) {
    auto task = bind(f, args...);
    {
        unique_lock<mutex> lock(queue_mutex);
        if (stop) return;
        tasks.push(task);
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (thread &worker :workers) {
        worker.join();
    }
}

void the_task(int i) {
    printf("worker thread ID: = %d i = %d\n", std::this_thread::get_id(), i);
}

int main() {
    ThreadPool pool(4);
    pool.push(the_task, 1);
    pool.push(the_task, 2);
    pool.push(the_task, 3);
    pool.push(the_task, 4);
    return 0;
}