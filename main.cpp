#include <bits/stdc++.h>

using namespace std;
int n;

void dfs(int pos, int num1, int num2, string s) {
    if (pos == 2 * n) {
        cout << s << endl;
        return;
    }
    if (num1 + 1 <= n && num1 + 1 >= num2) {
        dfs(pos + 1, num1 + 1, num2, s + '0');
    }
    if (num2 + 1 <= n && num1 >= num2 + 1) {
        dfs(pos + 1, num1, num2 + 1, s + '1');
    }
}

class A {
public:

private:
    A() : a(0) {}

    int a;
};

int main() {
    scanf("%d", &n);
    dfs(0, 0, 0, "");
    return 0;
}