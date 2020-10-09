#include <bits/stdc++.h>

using namespace std;

int a[] = {2, 1, 4, 1, 1};

void merge(int L1, int R1, int L2, int R2) {
    int temp[R2 - L1 + 1];
    int i = L1, j = L2, pos = 0;
    while (i <= R1 && j <= R2) {
        if (a[i] <= a[j]) {
            temp[pos++] = a[i];
            i++;
        } else {
            temp[pos++] = a[j];
            j++;
        }
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


int main() {
    mergeSort(0, 4);
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    return 0;
}