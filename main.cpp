#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
    int pre[100010];
    int len;

    ProductOfNumbers() {
        pre[0] = 1;
        len = 0;
    }

    void add(int num) {
        if (!num) len = 0;
        else {
            len++;
            pre[len] = num * pre[len - 1];
        }
    }

    int getProduct(int k) {
        if (len < k) return 0;
        return pre[len] / pre[len - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
int main() {

    return 0;
}