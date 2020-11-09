#include<bits/stdc++.h>

using namespace std;

/*
2. 检查两个表达式是否等价。表达式仅包含小写字母 'a'-'z', '+', '-', '(', ')'，且表达式里的未知数仅有一个字符。
例如：
1) exp1 = "a+b+c-a", exp2 = "(b+c)", result: true
2) exp1 = "a-b-c", exp2 = "a-(b+c)", result: true
3) exp1 = "a-b+c", exp2 = "a-(b+c)", result: false
4) exp1 = "a-b+c", exp2 = "a-(b-(c-d)-d)", result: true
5) exp1 = "a+d", exp2 = "b+c", result: false

bool check(const char* exp1, const char* exp2);
*/

map<char, int> mp1;
map<char, int> mp2;

void solve(string s, int vis, map<char, int> &mp) {
    char flag = '+';
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '+' || s[i] == '-') flag = s[i];
        else if (s[i] == '(') {
            int j = i, cnt = 0;
            for (; i < n; i++) {
                if (s[i] == '(') cnt++;
                else if (s[i] == ')') cnt--;
                if (cnt == 0) break;
            }
            int num;
            if (vis == 0) {
                num = flag == '+' ? 0 : 1;
            } else {
                num = flag == '+' ? 1 : 0;
            }
            solve(s.substr(j + 1, i - 1 - j), num, mp);
        } else {
            string cur, temp;
            if (vis == 0) {
                if (flag == '+') {
                    mp[s[i]]++;
                } else {
                    mp[s[i]]--;
                }
            } else {
                if (flag == '+') {
                    mp[s[i]]--;
                } else {
                    mp[s[i]]++;
                }
            }
        }
    }
}

bool check(string exp1, string exp2) {
    mp1.clear();
    mp2.clear();
    solve(exp1, 0, mp1);
    solve(exp2, 0, mp2);
    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        if (it->second == 0) mp1.erase(it++);
    }
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        if (it->second == 0) mp2.erase(it++);
    }
/*    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }*/
    if (mp1.size() != mp2.size()) return false;
    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        char ch = it->first;
        if (mp1[ch] != mp2[ch]) return false;
    }
    return true;
}


int main() {
    cout << check("a+b+c-a", "(b+c)") << endl;
    cout << check("a-b-c", "a-(b+c)") << endl;
    cout << check("a-b+c", "a-(b+c)") << endl;
    cout << check("a-b+c", "a-(b-(c-d)-d)") << endl;
    cout << check("a+d", "b+c") << endl;
    return 0;
}
