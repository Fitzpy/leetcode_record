#include <bits/stdc++.h>

using namespace std;

int a[] = {1, -2, 1, 0, 3};

void quickSort(int L, int R) {
    if (L > R) return;
    int i = L, j = R, val = a[L];
    while (i < j) {
        while (i < j && a[j] >= val) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= val) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = val;
    quickSort(L, i - 1);
    quickSort(i + 1, R);
}

void merge(int L1, int R1, int L2, int R2) {
    if (L1 > R1 || L2 > R2) return;
    int i = L1, j = L2, pos = 0;
    int temp[R2 - L1 + 1];
    while (i <= R1 && j <= R2) {
        if (a[i] < a[j]) temp[pos++] = a[i++];
        else temp[pos++] = a[j++];
    }
    while (i <= R1) temp[pos++] = a[i++];
    while (j <= R2) temp[pos++] = a[j++];
    for (i = L1; i <= R2; i++) {
        a[i] = temp[i - L1];
    }
}

void mergeSort(int L, int R) {
    if (L >= R) return;
    int mid = (L + R) / 2;
    mergeSort(L, mid);
    mergeSort(mid + 1, R);
    merge(L, mid, mid + 1, R);
}

int top, heap[10010];

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
    int ret = heap[1];
    heap[1] = heap[top];
    int root = 1;
    while (2 * root < top) {
        int L = root * 2, R = root * 2 + 1;
        if (R >= top || heap[L] <= heap[R]) {
            if (heap[L] <= heap[root]) {
                swap(heap[L], heap[root]);
                root = L;
            } else break;
        } else {
            if (heap[R] <= heap[root]) {
                swap(heap[R], heap[root]);
                root = R;
            } else break;
        }
    }
    top--;
    return ret;
}

int main() {
    for (int i = 0; i < 5; i++) push(a[i]);
    for (int i = 0; i < 5; i++) printf("%d ", pop());
    printf("\n");
    return 0;
}