#include <bits/stdc++.h>

using namespace std;

char s[10010];
struct node {
    char ch;
    int num;
} qu[10010];

int cmp(node a, node b) {
    if (a.num == b.num) return a.ch < b.ch;
    return a.num > b.num;
}

int check(char ch) {
    if (ch >= 'a' && ch <= 'z') return 1;
    if (ch >= 'A' && ch <= 'Z') return 1;
    if (ch >= '0' && ch <= '9') return 1;
    if (ch == ' ') return 1;
    return 0;
}

int main() {
    while (gets(s)) {
        int n = strlen(s);
        map<char, int> mp;
        mp.clear();
        for (int i = 0; i < n; i++) {
            if (check(s[i])) mp[s[i]]++;
        }
        int len = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->first << " " << it->second;
            qu[len].ch = it->first;
            qu[len].num = it->second;
            len++;
        }
        sort(qu, qu + len, cmp);
        for (int i = 0; i < len; i++) {
            printf("%c", qu[i].ch);
        }
        printf("\n");
    }
    return 0;
}