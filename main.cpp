#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        int a[15], len = 0;
        int ret = num;
        while (num) {
            a[len++] = num % 10;
            num /= 10;
        }
        reverse(a, a + len);
        int pos = 1;
        for (; pos < len; pos++) if (a[pos] > a[pos - 1]) break;
        if (pos == len) return ret;
        int maxx = a[pos], maxPos = pos;
        for (int i = pos; i < len; i++) {
            if (a[i] >= maxx) {
                maxx = a[i];
                maxPos = i;
            }
        }
        for (int i = 0; i < pos; i++) {
            if (a[i] < maxx) {
                swap(a[i], a[maxPos]);
                break;
            }
        }
        ret = 0;
        for (int i = 0; i < len; i++)
            ret = ret * 10 + a[i];
        return ret;
    }
};

int main() {
    return 0;
}