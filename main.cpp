#include <bits/stdc++.h>

using namespace std;

class ThreadPool {
public:
    ThreadPool(int threadNum, int queueSize);

    template<class F, class ...Args>
    void push(F &&f, Args ...args);

    ~ThreadPool();

private:
    bool stop;
    int size;
    mutex mutex;
    condition_variable produce, consume;
    vector<thread> workers;
    queue<function<void()>> tasks;
};

ThreadPool::ThreadPool(int threadNum, int queueSize) : stop(false), size(queueSize) {
    for (int i = 0; i < threadNum; i++) {
        workers.emplace_back([this] {
            for (;;) {
                function<void()> task;
                {
                    unique_lock<std::mutex> lock1(mutex);
                    consume.wait(lock1, [this] {
                        return this->stop || !this->tasks.empty();
                    });
                    if (this->stop && this->tasks.empty()) return;
                    task = move(this->tasks.front());
                    this->tasks.pop();
                    produce.notify_one();
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
        unique_lock<std::mutex> lock1(mutex);
        produce.wait(lock1, [this] {
            return tasks.size() != size;
        });
        tasks.push(task);
    }
    consume.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        unique_lock<std::mutex> lock1(mutex);
        stop = true;
    }
    consume.notify_all();
    for (thread &worker:workers) {
        worker.join();
    }
}

void the_task(int i) {
    printf("worker thread ID: = %d i = %d\n", std::this_thread::get_id(), i);
}

int main() {
    ThreadPool pool(2, 4);
    pool.push(the_task, 1);
    pool.push(the_task, 2);
    pool.push(the_task, 3);
    pool.push(the_task, 4);
    pool.push(the_task, 5);
    pool.push(the_task, 6);
    pool.push(the_task, 7);
    pool.push(the_task, 8);
    return 0;
}