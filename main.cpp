#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

    T *p;
    atomic<int> count;
};

template<typename T>
class SmartPtr {
public:
    SmartPtr(T *ptr) : rp(new U_Ptr<T>(ptr)) {}

    SmartPtr(const SmartPtr<T> &sp) : rp(sp.rp) {
        ++rp->count;
    }

    SmartPtr &operator=(const SmartPtr<T> &rhs) {
        ++rhs.rp->count;
        if (--rp->count == 0) delete rp;
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

int main() {
    int *i = new int(2);
    {
        SmartPtr<int> ptr1(i);
        {
            SmartPtr<int> ptr2(ptr1);
            {
                SmartPtr<int> ptr3 = ptr2;
                cout << *ptr1 << endl;
                *ptr1 = 20;
                cout << *ptr2 << endl;
            }
        }
    }
    system("pause");
    return 0;
}