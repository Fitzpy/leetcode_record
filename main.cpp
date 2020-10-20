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

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main() {
    return 0;
}