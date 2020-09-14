#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool vis[205][205];
    int n, m;
    bool ans;
    struct node {
        int x, y;
    };
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int check(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) return 0;
        return 1;
    }

    void dfs(int x, int y, string word, int pos, vector<vector<char>> &board) {
        if (word.size() - 1 == pos) {
            ans = true;
            return;
        }
        if (ans) return;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && board[nx][ny] == word[pos + 1]) {
                printf("x = %d y = %d\n", nx, ny);
                vis[nx][ny] = true;
                dfs(nx, ny, word, pos + 1, board);
                vis[nx][ny] = false;
            }
        }
    }

    int getNum(char ch) {
        if (ch >= 'A' && ch <= 'Z') return (ch - 'A');
        if (ch >= 'a' && ch <= 'z') return (ch - 'a') + 30;
        return 0;
    }

    bool exist(vector<vector<char>> &board, string word) {

        n = board.size();
        if (n == 0) return false;
        m = board[0].size();
        ans = false;
        vector<node> mp[60];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] >= 'A' && board[i][j] <= 'Z') mp[(board[i][j] - 'A')].push_back({i, j});
                if (board[i][j] >= 'a' && board[i][j] <= 'z') mp[(board[i][j] - 'a') + 30].push_back({i, j});
            }
        }
        for (int i = 0; i < mp[getNum(word[0])].size(); i++) {
            memset(vis, 0, sizeof(vis));
            vis[mp[getNum(word[0])][i].x][mp[getNum(word[0])][i].y] = true;
            dfs(mp[getNum(word[0])][i].x, mp[getNum(word[0])][i].y, word, 0, board);
            if (ans) return ans;
        }
        return ans;
    }
};

int main() {
    return 0;
}