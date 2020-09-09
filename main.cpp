#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();
        int flag = 0, x = 0, y = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int num = 0;
        while (1) {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -1000000;
            num++;
            if (num == n * m) break;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[(flag + i) % 4], ny = y + dy[(flag + i) % 4];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || matrix[nx][ny] == -1000000) continue;
                flag = (flag + i) % 4;
                x = nx, y = ny;
                break;
            }
        }
        return ans;
    }
} solve;

int main() {
    int n = 3, m = 3;
    vector<vector<int>> in;
    for (int i = 0; i < n; i++) {
        vector<int> cnt;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            cnt.push_back(x);
        }
        in.push_back(cnt);
    }
    auto ans = solve.spiralOrder(in);
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}