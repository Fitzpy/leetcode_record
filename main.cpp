#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        vector<int> num(len1 + len2 + 10, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int pos = i + j;
                num[pos] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int res = 0;
        for (int i = 0; i < len1 + len2 + 1; i++) {
            num[i] += res;
            res = num[i] / 10;
            num[i] %= 10;
        }
        string ret;
        int pos = len1 + len2 + 1;
        while (pos >= 0 && num[pos] == 0) pos--;
        if (pos < 0) ret += '0';
        for (int i = pos; i >= 0; i--) ret += num[i] + '0';
        return ret;
    }
};

int main() {

    return 0;
}