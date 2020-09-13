#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int pos = 0;
        while (str[pos] == ' ') pos++;
        long long maxx = ((long long) 1 << 31) - 1, minn = -((long long) 1 << 31);
        if (str[pos] == '+' || str[pos] == '-') {
            long long ans = 0;
            for (int i = pos + 1; i < len; i++) {
                if (str[i] >= '0' && str[i] <= '9') ans = ans * 10 + str[i] - '0';
                else {
                    if (str[pos] == '+') {
                        return int(min(ans, maxx));
                    }
                    if (str[pos] == '-') {
                        return int(max(-ans, minn));
                    }
                }
                if (str[pos] == '+' && ans >= maxx) {
                    return int(min(ans, maxx));
                }
                if (str[pos] == '-' && ans >= -minn) {
                    return int(max(-ans, minn));
                }
            }
            if (str[pos] == '+') {
                return int(min(ans, maxx));
            }
            if (str[pos] == '-') {
                return int(max(-ans, minn));
            }
        } else if (str[pos] >= '0' && str[pos] <= '9') {
            long long ans = 0;
            for (int i = pos; i < len; i++) {
                if (str[i] >= '0' && str[i] <= '9') ans = ans * 10 + str[i] - '0';
                else {
                    return int(min(ans, maxx));
                }
                if (ans >= maxx) {
                    return int(min(ans, maxx));
                }
            }
            return int(min(ans, maxx));
        } else {
            return 0;
        }
        return 0;
    }
} ;

int main() {

    return 0;
}