#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;

int a[5] = {2, 3, 1, 4, 5};

void quick_sort(int L, int R) {
    if (L > R) return;
    int i = L, j = R, x = a[L];
    while (i < j) {
        while (i < j && a[j] >= x) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= x) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = x;
    quick_sort(L, i - 1);
    quick_sort(i + 1, R);
}

int heap[maxn], top = 0;

void push(int val) {
    heap[++top] = val;
    int temp = top;
    while (temp > 1) {
        int root = temp / 2;
        if (heap[root] > val) {
            swap(heap[root], heap[temp]);
            temp = root;
        } else break;
    }
}

int pop() {
    if (top == 0) return -999999;
    int ret = heap[1];
    heap[1] = heap[top];
    int root = 1;
    while (2 * root < top) {
        int left = 2 * root, right = 2 * root + 1;
        if (right >= top || heap[left] < heap[right]) {
            if (heap[left] < heap[root]) {
                swap(heap[left], heap[root]);
                root = left;
            } else break;
        } else {
            if (heap[right] < heap[root]) {
                swap(heap[right], heap[root]);
                root = right;
            } else break;
        }
    }
    top--;
    return ret;
}

template<typename T>
class SmartPtr;

template<typename T>
class U_Ptr {
private:
    friend class SmartPtr<T>;

    U_Ptr(T *ptr) : p(ptr), count(1) {}

    ~U_Ptr() {
        delete p;
    }

    atomic<int> count;
    T *p;
};

template<typename T>
class SmartPtr {
public:
    SmartPtr(T *ptr) : rp(new U_Ptr<T>(ptr)) {}

    SmartPtr(const SmartPtr<T> &rhs) : rp(rhs.rp) {
        ++rp->count;
    }

    SmartPtr &operator=(const SmartPtr<T> &rhs) {
        ++rhs.rp->count;
        if (--rp->count == 0) {
            delete rp;
        }
        rp = rhs.rp;
        return *this;
    }

    T &operator*() {
        return *(rp->p);
    }

    T *operator->() {
        return rp->p;
    }

    ~SmartPtr() {
        if (--rp->count == 0) {
            delete rp;
        } else cout << "还有" << rp->count << "个指针指向基础对象" << endl;
    }

private:
    U_Ptr<T> *rp;
};

class MyString {
public:
    MyString(const char *str) {
        if (str == NULL) {
            data = new char[1];
            *data = '\0';
        } else {
            int len = strlen(str);
            data = new char[len + 1];
            strcpy(data, str);
        }
    }

    MyString(const MyString &str) {
        int len = strlen(str.data);
        if (len == 0) {
            data = new char[1];
            *data = '\0';
        } else {
            data = new char[len + 1];
            strcpy(data, str.data);
        }
    }

    MyString &operator=(const MyString &str) {
        if (this == &str) {
            return *this;
        }
        delete data;
        int len = strlen(str.data);
        data = new char[len + 1];
        strcpy(data, str.data);
        return *this;
    }

    ~MyString() {
        delete data;
    }

private:
    char *data;
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int len = A.size();
        int L = 0, R = len - 1;
        while (L < R) {
            if (A[L] & 1) {
                while (A[R] & 1) {
                    R--;
                }
                swap(A[L], A[R]);
            }
        }
        return A;
    }
};

int main() {

    return 0;
}