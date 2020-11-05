#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 7;

class lockFreeQueue {
public:
    lockFreeQueue() {
        writeIndex = readIndex = maxReadIndex = 0;
    }

    bool push(int val) {
        int currentReadIndex, currentWriteIndex, nextWriteIndex;
        do {
            currentWriteIndex = writeIndex;
            currentReadIndex = readIndex;
            nextWriteIndex = (writeIndex + 1) % maxn;
            if (nextWriteIndex == currentReadIndex) {
                return false;//full
            }
        } while (!__sync_bool_compare_and_swap(&writeIndex, currentWriteIndex, nextWriteIndex));
        data[currentWriteIndex] = val;
        while (!__sync_bool_compare_and_swap(&maxReadIndex, currentWriteIndex, nextWriteIndex)) {
            std::this_thread::yield();
        }
        return true;
    }

    bool pop(int &ret) {
        int currentMaxReadIndex;
        int currentReadIndex;
        int nextReadIndex;
        do {
            currentReadIndex = readIndex;
            currentMaxReadIndex = maxReadIndex;
            nextReadIndex = (currentReadIndex + 1) % maxn;
            if (currentReadIndex == currentMaxReadIndex) {
                //队列为空或生产者线程在队列中分配了空间，但是等待将数据提交到其中
                return false;
            }
            ret = data[currentReadIndex];
        } while (!__sync_bool_compare_and_swap(&readIndex, currentReadIndex, nextReadIndex));
        return true;
    }

private:
    int writeIndex, readIndex, maxReadIndex;
    int data[maxn];
};

lockFreeQueue que;

void func1() {
    for (int i = 0; i < 10; i++) {
        que.push(i);
    }
}

void func2() {
    for (int i = 30; i < 40; i++) {
        que.push(i);
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        int ret;
        que.pop(ret);
        printf("%d ",ret);
    }
    printf("\n");
}

int main() {
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);
    std::thread t4(func3);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
