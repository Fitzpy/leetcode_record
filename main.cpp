#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++) {
            int num = 0, cur = 0;
            unordered_map<string, int> mp;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    num++;
                    continue;
                }
                int y = points[j][1] - points[i][1];
                int x = points[j][0] - points[i][0];
                int val = __gcd(x, y);
                y /= val, x /= val;
                if (y > 0 && x < 0) y = -y, x = -x;
                string s = to_string(y) + '/' + to_string(x);
                mp[s]++;
                cur = max(cur, mp[s]);
            }
            ret = max(ret, cur + num + 1);
        }
        return ret;
    }
};

int main() {
    int num = -3, num1 = -6;
    cout << to_string(num);
    return 0;
}