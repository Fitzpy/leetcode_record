# 题目合集

## 105. 从前序与中序遍历序列构造二叉树

```
class Solution {
public:
    TreeNode *calTree(vector<int> &preorder, vector<int> &inorder,
                      int preLeft, int preRight, int inoLeft, int inoRight) {
        if (preLeft > preRight) return NULL;
        int pos = mp[preorder[preLeft]];
        int len = pos - inoLeft;
        TreeNode *node = new TreeNode(preorder[preLeft]);
        node->left = calTree(preorder, inorder, preLeft+1, preLeft + len, inoLeft, pos - 1);
        node->right = calTree(preorder, inorder, preLeft + len + 1, preRight, pos + 1, inoRight)
        return node;
    }

    unordered_map<int, int> mp;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        mp.clear();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return calTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
```
## 106. 从中序与后序遍历序列构造二叉树

```
class Solution {
public:
    TreeNode *calTree(vector<int> &inorder, vector<int> &postorder,
                      int inoLeft, int inoRight, int postLeft, int postRight) {
        if (postLeft > postRight) return NULL;
        int pos = mp[postorder[postRight]];
        int len = pos - inoLeft;
        TreeNode *node = new TreeNode(postorder[postRight]);
        node->left = calTree(inorder, postorder, inoLeft, pos - 1, postLeft, postLeft + len - 1);
        node->right = calTree(inorder, postorder, pos + 1, inoRight, postLeft + len, postRight - 1);
        return node;
    }

    unordered_map<int, int> mp;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        mp.clear();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return calTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
```
## 378. 有序矩阵中第K小的元素
```
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        priority_queue<int> que;
        while (!que.empty())que.pop();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (que.size() < k) {
                    que.push(matrix[i][j]);
                } else {
                    que.push(matrix[i][j]);
                    que.pop();
                }
            }
        }
        return que.top();
    }
};
```
## 41. 缺失的第一个正数
```
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num<= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
```
## 912. 排序数组(堆排序，快排，归并排序)
```
class Solution {
public:
    void push(int val) {
        heap[++top] = val;
        int temp = top;
        while (temp > 1) {
            int root = temp / 2;
            if (heap[root] > val) swap(heap[root], heap[temp]);
            else break;
            temp = root;
        }
    }

    int pop() {
        if (top == 0) return -999999;
        int ret = heap[1];
        heap[1] = heap[top];
        int root = 1;
        while (2 * root < top) {
            int L = root * 2;
            int R = root * 2 + 1;
            if (R >= top || heap[L] < heap[R]) {
                if (heap[root] > heap[L]) {
                    swap(heap[root], heap[L]);
                    root = L;
                } else break;
            } else {
                if (heap[root] > heap[R]) {
                    swap(heap[root], heap[R]);
                    root = R;
                } else break;
            }
        }
        top--;
        return ret;
    }

    vector<int> sortArray(vector<int> &nums) {
        top = 0;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            push(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(pop());
        }
        return ans;
    }

private:
    int top, heap[100010];
};

class Solution {
public:
    void quick_sort(vector<int> &nums, int L, int R) {
        if (L >= R) return;
        int i = L, j = R, x = nums[L];
        while (i < j) {
            while (i < j && x <= nums[j]) j--;
            if (i < j) nums[i++] = nums[j];
            while (i < j && x >= nums[i]) i++;
            if (i < j) nums[j--] = nums[i];
        }
        nums[i] = x;
        quick_sort(nums, L, i - 1);
        quick_sort(nums, i + 1, R);
    }

    vector<int> sortArray(vector<int> &nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

};
归并排序
void merge(int L1, int R1, int L2, int R2) {
    int temp[R2 - L1 + 1];
    int i = L1, j = L2, pos = 0;
    while (i <= R1 && j <= R2) {
        if (a[i] <= a[j]) {
            temp[pos++] = a[i];
            i++;
        } else {
            temp[pos++] = a[j];
            j++;
        }
    }
    while (i <= R1) temp[pos++] = a[i++];
    while (j <= R2) temp[pos++] = a[j++];
    for (i = L1; i <= R2; i++) {
        a[i] = temp[i - L1];
    }
}

void mergeSort(int L, int R) {
    if (L >= R) return;
    int mid = (L + R) / 2;
    mergeSort(L, mid);
    mergeSort(mid + 1, R);
    merge(L, mid, mid + 1, R);
}
```

## 54. 螺旋矩阵
```
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
```

## 415. 字符串相加
```
class Solution {
public:
    int num[100010];

    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int cy = 0;
        for (int i = 0; i < min(n, m); i++) {
            int val = num1[i] - '0' + num2[i] - '0' + cy;
            num[i] = val % 10;
            cy = val / 10;
        }
        if (n >= m) {
            for (int i = min(n, m); i < max(n, m); i++) {
                int val = num1[i] - '0' + cy;
                num[i] = val % 10;
                cy = val / 10;
            }
        } else {
            for (int i = min(n, m); i < max(n, m); i++) {
                int val = num2[i] - '0' + cy;
                num[i] = val % 10;
                cy = val / 10;
            }
        }
        int len = max(n, m);
        if (cy) num[max(n, m)] = cy, len++;
        string ans;
        for (int i = 0; i < len; i++) {
            ans += std::to_string(num[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## 8. 字符串转换整数 (atoi)
```
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
```

## 93. 复原IP地址
```
class Solution {
public:
    int check(string &s, int L, int R) {
        int len = R - L + 1;
        if (len == 0) return 0;
        if (len == 1 && s[L] == '0') return 1;
        int flag = 0, ans = 0;
        for (int i = L; i <= R; i++) {
            if (s[i] == '0' && flag == 0) return 0;
            if (s[i] != '0' && flag == 0) flag = 1;
            ans = ans * 10 + s[i] - '0';
            if (ans > 255) return 0;
        }
        return 1;
    }

    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        string s1, s2, s3, s4;
        vector<string> ret;
        for (int i = 0; i < len - 3; i++) {
            if (!check(s, 0, i)) continue;
            for (int j = i + 1; j < len - 2; ++j) {
                if (!check(s, i + 1, j)) continue;
                for (int k = j + 1; k < len - 1; ++k) {
                    if (check(s, j + 1, k) && check(s, k + 1, len - 1)) {
                        s1 = s.substr(0, i + 1);
                        s2 = s.substr(i + 1, j - i);
                        s3 = s.substr(j + 1, k - j);
                        s4 = s.substr(k + 1, len - k);
                        cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
                        string ans = (s1 + "." + s2 + "." + s3 + "." + s4);
                        ret.push_back(ans);
                    }
                }
            }
        }
        return ret;
    }
} solve;
```
## 543 二叉树的直径

```
class Solution {
public:
    int ans;

    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        ans = 1;
        depth(root);
        return ans-1;
    }
};
```

## 384. 打乱数组
```
class Solution {
public:
    Solution(vector<int>& nums) {
        v = nums;
        ans = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = v;
        return ans;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int len = ans.size();
        for (int i=0 ;i<len ;i++){
            int idx = rand()%(i+1);
            swap(ans[i],ans[idx]);
        }
        return ans;
    }

private:
    vector<int>v;
    vector<int>ans;
};
```
## 257. 二叉树的所有路径
```
class Solution {
public:
    vector<string> ret;

    void dfs(TreeNode *root, string s) {
        if (root != nullptr) {
            s += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                ret.push_back(s);
            }else {
                s += "->";
                dfs(root->left,s);
                dfs(root->right,s);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        ret.clear();
        dfs(root,"");
        return ret;
    }
};
```

## 剑指 Offer 24. 反转链表

```
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = NULL, *pre = head;
        while(pre!=NULL) {
            ListNode * now = pre->next;
            pre->next = cur;
            cur = pre;
            pre = now;
        }
        return cur;
    }
};
```

## 94. 二叉树的中序遍历

```
class Solution {
public:

    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *cur = root;
        vector<int> ans;
        stack<TreeNode *> st;
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
```

## 144. 二叉树的前序遍历

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return ans;
    }
};
```

## 145. 二叉树的后序遍历
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode * cur = root;
        while(cur !=NULL || !st.empty()) {
            while(cur!=NULL){
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur ->right;
            }
            cur = st.top();
            st.pop();
            cur = cur ->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

## 79. 单词搜索
```
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
            // printf("x = %d y = %d\n",mp[(word[0] - 'A')][i].x, mp[(word[0] - 'A')][i].y);
            memset(vis, 0, sizeof(vis));
            vis[mp[getNum(word[0])][i].x][mp[getNum(word[0])][i].y] = true;
            dfs(mp[getNum(word[0])][i].x, mp[getNum(word[0])][i].y, word, 0, board);
            if (ans) return ans;
        }
        return ans;
    }
};
```
## 剑指 Offer 45. 把数组排成最小的数
```
class Solution {
public:
    static bool cmp(string &s1, string &s2) {
        return s1 + s2 < s2 + s1;
    }

    string minNumber(vector<int> &nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            ans.push_back(s);
        }
        sort(ans.begin(), ans.end(), cmp);
        string ret;
        for (int i = 0; i < ans.size(); i++) {
            ret += ans[i];
        }
        return ret;
    }
};
```

## 141. 环形链表
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> mp;
        while (head != NULL) {
            if (mp.count(head)) {
                return true;
            } else {
                mp[head] = 1;
                head = head->next;
            }
        }
        return false;
    }
};
```
## 剑指 Offer 48. 最长不含重复字符的子字符串
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>vis;
        vis.clear();
        int len = s.size();
        int L = 0, R = 0, ans = 0;
        while (R<len) {
            if (!vis[s[R]]) {
                vis[s[R]]++;
                ans = max(ans, R - L + 1);
                R++;
            } else {
                char pos = s[R];
                while (L <= R) {
                    vis[s[L]]--;
                    L++;
                    if (!vis[pos]) break;
                }
            }
        }
        return ans;
    }
} ;
```

## 110. 平衡二叉树
```
class Solution {
public:
    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        return max(L, R) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (abs(depth(root->left)-depth(root->right))>1) return false;
        else return (isBalanced(root->left)&isBalanced(root->right));
    }
};
```
## 剑指 Offer 39. 数组中出现次数超过一半的数字
```
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int len = nums.size();
        int key = nums[0], num = 1;
        for (int i = 1; i < len; i++) {
            if (num == 0) {
                key = nums[i];
                num = 1;
            } else if (nums[i] != key) {
                num--;
            } else {
                num++;
            }
        }
        return key;
    }
};
```
## 42. 接雨水
```
class Solution {
public:
    int L[100010], R[100010];

    int trap(vector<int> &height) {
        int len = height.size();
        for (int i = 1; i <= len; i++) {
            L[i] = max(L[i - 1], height[i - 1]);
        }
        for (int i = len; i >= 1; i--) {
            R[i] = max(R[i + 1], height[i - 1]);
        }
        int sum = 0;
        for (int i = 1; i <= len; i++) {
            int minn = min(L[i - 1], R[i + 1]);
            if (height[i - 1] < minn) {
                sum += minn - height[i - 1];
            }
        }
        return sum;
    }
};
```

## 11. 盛最多水的容器
```
class Solution {
public:
    int maxArea(vector<int> &height) {
        int low = 0, high = height.size() - 1;
        int ans = 0;
        while (low < high) {
            ans = max(ans, min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return ans;
    }
};
```
## 53. 最大子序和
```
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0], pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = max(pre+nums[i],nums[i]);
            ans = max(ans,pre);
        }
        return ans;
    }
};
```

## 239. 滑动窗口最大值
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> deq;
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i < k) {
                if (deq.empty()) deq.push_back(i);
                else {
                    while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
                    deq.push_back(i);
                }
                if (i==k-1 ) ans.push_back(nums[deq.front()]);
            } else {
                if (!deq.empty() && i - deq.front() >= k) deq.pop_front();
                if (deq.empty()) deq.push_back(i);
                else {
                    while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
                    deq.push_back(i);
                }
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
} ;
```

## 手写string类
```
class String {
public:
    String(const char *str);

    String(const String &s);

    String &operator=(const String &s);

    ~String();

private:
    char *data;
};

String::String(const char *str) {
    if (str == NULL) {
        data = new char[1];
        *data = '\0';
    } else {
        int len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}

String::String(const String &s) {
    int len = strlen(s.data);
    if (len == 0) {
        data = new char[1];
        *data = '\0';
    } else {
        data = new char[len + 1];
        strcpy(data, s.data);
    }
}

String &String::operator=(const String &s) {
    //检查是否是自赋值
    if (this == &s) {
        return *this;
    }
    delete[]data;
    int len = strlen(s.data);
    data = new char[len + 1];
    strcpy(data, s.data);
    return *this;
}

String::~String() {
    delete[]data;
}
``` 

## 382. 链表随机节点
```
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        Head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur = Head;
        int num = 0, ret = Head->val;
        while (cur) {
            int now = rand() % (num + 1);
            num++;
            if (now == 0) {
                ret = cur->val;
            }
            cur = cur->next;
        }
        return ret;
    }

private:
    ListNode *Head;
};
```

## 剑指 Offer 22. 链表中倒数第k个节点

```
class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *now1 = head, *now2 = head;
        int num = 0;
        while (now2 != NULL) {
            num++;
            if (num <= k) {
                now2 = now2->next;
            } else {
                now1 = now1->next;
                now2 = now2->next;
            }
        }
        return now1;
    }
};
```

## 手写share_ptr
```
//模板类作为友元时要先有声明
template <typename T>
class ~~SmartPtr~~;
template <typename T>
class U_Ptr     //辅助类
{
private:
    //该类成员访问权限全部为private，因为不想让用户直接使用该类
    friend class SmartPtr<T>;      //定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
    //构造函数的参数为基础对象的指针
    U_Ptr(T *ptr) :p(ptr), count(1) { }
    //析构函数
    ~U_Ptr() { delete p; }
    //引用计数
    int count;
    //基础对象指针
    T *p;
};
template <typename T>
class SmartPtr   //智能指针类
{
public:
    SmartPtr(T *ptr) :rp(new U_Ptr<T>(ptr)) { }      //构造函数
    SmartPtr(const SmartPtr<T> &sp) :rp(sp.rp) { ++rp->count; }  //复制构造函数
    SmartPtr& operator=(const SmartPtr<T>& rhs) {    //重载赋值操作符
        ++rhs.rp->count;     //首先将右操作数引用计数加1，
        if (--rp->count == 0)     //然后将引用计数减1，可以应对自赋值
            delete rp;
        rp = rhs.rp;
        return *this;
    }
    T & operator *()        //重载*操作符  
    {
        return *(rp->p);
    }
    T* operator ->()       //重载->操作符  
    {
        return rp->p;
    }
    ~SmartPtr() {        //析构函数
        if (--rp->count == 0)    //当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
            delete rp;
        else cout << "还有" << rp->count << "个指针指向基础对象" << endl;
    }
private:
    U_Ptr<T> *rp;  //辅助类对象指针
};
int main()
{
    int *i = new int(2);
    {
        SmartPtr<int> ptr1(i);
        {
            SmartPtr<int> ptr2(ptr1);
            {
                SmartPtr<int> ptr3 = ptr2;
                cout << *ptr1 << endl;
                *ptr1 = 20;
                cout << *ptr2 << endl;
            }
        }
    }
    system("pause");
    return 0;
}
```

## C++简易线程池 可能出现BUG
```
class ThreadPool {
public:
    ThreadPool(int threads);

    template<class F, class ...Args>
    void push(F &&f, Args &&...args);

    ~ThreadPool();

private:
    bool stop;
    mutex queue_mutex;
    condition_variable condition;
    vector<thread> workers;
    queue<function<void()>> tasks;
};

ThreadPool::ThreadPool(int threads) : stop(false) {
    for (int i = 0; i < threads; i++) {
        workers.emplace_back(
                [this] {
                    while (1) {
                        function<void()> task;
                        {
                            unique_lock<mutex> lock(this->queue_mutex);
                            condition.wait(lock, [this] {
                                return this->stop || !this->tasks.empty();
                            });
                            if (this->stop && this->tasks.empty()) return;
                            task = move(tasks.front());
                            tasks.pop();
                        }
                        task();
                    }
                }
        );
    }
}

template<class F, class ...Args>
void ThreadPool::push(F &&f, Args &&...args) {
    auto task = bind(f, args...);
    {
        unique_lock<mutex> lock(queue_mutex);
        if (stop) return;
        tasks.push(task);
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (thread &worker :workers) {
        worker.join();
    }
}

void the_task(int i) {
    printf("worker thread ID: = %d i = %d\n", std::this_thread::get_id(), i);
}

int main() {
    ThreadPool pool(4);
    pool.push(the_task, 1);
    pool.push(the_task, 2);
    pool.push(the_task, 3);
    pool.push(the_task, 4);
    return 0;
}

+ 带有任务队列大小版本的
class ThreadPool {
public:
    ThreadPool(int threadNum, int queueSize);

    template<class F, class ...Args>
    void push(F &&f, Args ...args);

    ~ThreadPool();

private:
    bool stop;
    int size;
    mutex mutex;
    condition_variable produce, consume;
    vector<thread> workers;
    queue<function<void()>> tasks;
};

ThreadPool::ThreadPool(int threadNum, int queueSize) : stop(false), size(queueSize) {
    for (int i = 0; i < threadNum; i++) {
        workers.emplace_back([this] {
            for (;;) {
                function<void()> task;
                {
                    unique_lock<std::mutex> lock1(mutex);
                    consume.wait(lock1, [this] {
                        return this->stop || !this->tasks.empty();
                    });
                    if (this->stop && this->tasks.empty()) return;
                    task = move(this->tasks.front());
                    this->tasks.pop();
                    produce.notify_one();
                }
                task();
            }
        });
    }
}

template<class F, class ...Args>
void ThreadPool::push(F &&f, Args ...args) {
    auto task = bind(f, args...);
    {
        unique_lock<std::mutex> lock1(mutex);
        produce.wait(lock1, [this] {
            return tasks.size() != size;
        });
        tasks.push(task);
    }
    consume.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        unique_lock<std::mutex> lock1(mutex);
        stop = true;
    }
    consume.notify_all();
    for (thread &worker:workers) {
        worker.join();
    }
}

void the_task(int i) {
    printf("worker thread ID: = %d i = %d\n", std::this_thread::get_id(), i);
}

int main() {
    ThreadPool pool(2, 4);
    pool.push(the_task, 1);
    pool.push(the_task, 2);
    pool.push(the_task, 3);
    pool.push(the_task, 4);
    pool.push(the_task, 5);
    pool.push(the_task, 6);
    pool.push(the_task, 7);
    pool.push(the_task, 8);
    return 0;
}
```

## C++简易HashMap
```
class HashMap {
public:
    HashMap() {
        capacity = 10;
        mp.resize(capacity);
    }

    void put(unsigned long long key, int val);

    int get(unsigned long long key);

    void rehash();

private:
    vector<list<pair<unsigned long long, int>>> mp;
    int capacity;
    int size = 0;
    unsigned long long seed = 13331;
};

void HashMap::put(unsigned long long key, int val) {
    int idx = key % capacity;
    for (auto it = mp[idx].begin(); it != mp[idx].end(); it++) {
        if (it->first == key) {
            it->second = val;
            return;
        }
    }
    size++;
    mp[idx].push_back(make_pair(key, val));
    if (size == capacity) rehash();
}

int HashMap::get(unsigned long long key) {
    int idx = key % capacity;
    for (auto it = mp[idx].begin(); it != mp[idx].end(); it++) {
        if (it->first == key) {
            return it->second;
        }
    }
    return -1;
}

void HashMap::rehash() {
    capacity *= 2;
    mp.resize(capacity);
    for (int i = 0; i < capacity / 2; i++) {
        for (auto it = mp[i].begin(); it != mp[i].end(); it++) {
            unsigned long long key = it->first;
            int val = it->second;
            int idx = key % (2 * capacity);
            if (idx == i) continue;
            put(key, val);
        }
    }
}

```

## 337. 打家劫舍 III
```
class Solution {
public:
    unordered_map<TreeNode *, int> mp1, mp2;

    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        mp1[root] = root->val + mp2[root->left] + mp2[root->right];
        mp2[root] = max(mp1[root->left], mp2[root->left]) + max(mp1[root->right], mp2[root->right]);

    }

    int rob(TreeNode *root) {
        mp1.clear();
        mp2.clear();
        dfs(root);
        return max(mp1[root], mp2[root]);
    }
};

```
## 剑指 Offer 27. 二叉树的镜像
```
class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == NULL) return root;
        TreeNode *temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};
```

## 4. 寻找两个正序数组的中位数
```
class Solution {
public:
    int find_kth(vector<int> &nums1, vector<int> &nums2, int pos1, int pos2, int num) {
        if (pos1 == nums1.size()) {
            return nums2[pos2 + num - 1];
        }
        if (pos2 == nums2.size()) {
            return nums1[pos1 + num - 1];
        }
        if (num == 1) {
            return min(nums1[pos1], nums2[pos2]);
        }
        int len1 = num / 2;
        int len2 = num - len1;
        int newPos1 = min(pos1 + len1 - 1, (int) nums1.size() - 1);
        int newPos2 = min(pos2 + len2 - 1, (int) nums2.size() - 1);
        if (nums1[newPos1] < nums2[newPos2]) {
            return find_kth(nums1, nums2, newPos1 + 1, pos2, num - (newPos1 - pos1 + 1));
        } else {
            return find_kth(nums1, nums2, pos1, newPos2 + 1, num - (newPos2 - pos2 + 1));
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1) {
            return double(find_kth(nums1, nums2, 0, 0, (len + 1) / 2));
        } else {
            return double(
                    (find_kth(nums1, nums2, 0, 0, len / 2) +
                     find_kth(nums1, nums2, 0, 0, len / 2 + 1)) / 2.0);
        }
    }
};
```
## 206. 反转链表
```
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = head;
        ListNode *cur = NULL;
        while (pre != NULL) {
            ListNode *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};
```
## 面试题 17.14. 最小K个数
```
class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        priority_queue<int> que;
        for (int i = 0; i < arr.size(); i++) {
            if (que.size() < k) {
                que.push(arr[i]);
            } else {
                que.push(arr[i]);
                que.pop();
            }
        }
        vector<int> ret;
        while (!que.empty()) {
            ret.push_back(que.top());
            que.pop();
        }
        return ret;
    }
};
```

## 64. 最小路径和
```
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < m; i++) {
            if (i == 0) dp[0][i] = grid[0][i];
            else dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
```

## 33. 搜索旋转排序数组
```
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int len = nums.size() - 1;
        int low = 0, high = len, ans = -1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            printf("mid = %d\n", mid);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[0] <= nums[mid]) {
                if (nums[mid] > target && nums[0] <= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] <= nums[len]) {
                if (nums[mid] < target && nums[len] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
} solve;
```
## 手写strcpy
```
char *MyStrCpy(char *dst, char *src) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char *pdst = dst;
    char *psrc = src;
    int len = strlen(src)+1; //处理'\0'
    if (src < dst && src + len > dst) {
        pdst += len - 1;
        psrc += len - 1;
        while (len--) {
            *pdst-- = *psrc--;
        }
    } else {
        while ((*pdst++ = *psrc++) != '\0');
    }
    return dst;
}
```
## 手写MemCpy
```
void *MemCpy(char *dst, char *src, int size) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char *pdst = dst;
    char *psrc = src;
    if ((src < dst) && src + size > dst) {
        pdst += size - 1;
        psrc += size - 1;
        while (size--) {
            *pdst-- = *psrc--;
        }
    } else {
        while (size--) {
            *pdst++ = *psrc++;
        }
    }
    return dst;
}

```

## 905. 按奇偶排序数组
```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int len = A.size();
        int L = 0, R = len - 1;
        while (L < R) {
            if (A[L] & 1) {
                while (A[R] & 1) {
                    R--;
                    if (L>=R) return A;
                }
                swap(A[L], A[R]);
            }
            L++;
        }
        return A;
    }
};
```

## 138. 复制带随机指针的链表
```
class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> mp;
        Node *temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            Node *node = mp[temp];
            node->next = mp[temp->next];
            node->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

```

20. 有效的括号
```
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (st.empty() || s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if (s[i] == ')') {
                    if (st.top() != '(') return false;
                    else st.pop();
                }
                if (s[i] == '}') {
                    if (st.top() != '{') return false;
                    else st.pop();
                }
                if (s[i] == ']') {
                    if (st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
};
```

## 面试题 08.06. 汉诺塔问题
```
class Solution {
public:
    void hanota(vector<int> &A, vector<int> &B, vector<int> &C) {
        int n = A.size();
        solve(n, A, B, C);
    }

    void solve(int n, vector<int> &A, vector<int> &B, vector<int> &C) {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        solve(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        solve(n - 1, B, A, C);
    }
};

```

## 647. 回文子串
```
class Solution {
public:
    int countSubstrings(string s) {
        string cur;
        cur += '$';
        cur += '#';
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cur += s[i];
            cur += '#';
        }
        vector<int> mp(cur.size() + 5, 0);
        int maxlen = 0, res = 0, mx = 0, id = 0;
        for (int i = 1; i < cur.size(); i++) {
            mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
            while (cur[i + mp[i]] == cur[i - mp[i]]) mp[i]++;
            if (i + mp[i] > mx) {
                mx = i + mp[i];
                id = i;
            }
            maxlen = max(maxlen, mp[i] - 1);
            res += mp[i] / 2;
        }
        cout<<res<<endl;
        return res;
    }
}solve;
```

## 5. 最长回文子串
```
class Solution {
public:
    string longestPalindrome(string s) {
        string cur;
        cur += "$#";
        for (int i = 0; i < s.size(); i++) {
            cur += s[i];
            cur += '#';
        }
        vector<int> mp(cur.size() + 1, 0);
        int maxlen = 0, mx = 0, id = 0, ans = 0;
        for (int i = 1; i < cur.size(); i++) {
            mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
            while (cur[i + mp[i]] == cur[i - mp[i]]) mp[i]++;
            if (mp[i] + i > mx) {
                mx = mp[i] + i;
                id = i;
            }
            if (mp[i] - 1 > maxlen) {
                maxlen = mp[i] - 1;
                ans = i;
            }
        }
        string ret;
        for (int i = ans - mp[ans]+1; i < ans + mp[ans]; i++) {
            if (cur[i] != '#' && cur[i] !='$')  ret += cur[i];
        }
        return ret;
    }
};
```
## 剑指 Offer 04. 二维数组中的查找
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};
```
## 74. 搜索二维矩阵
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int x = mid / m, y = mid % m;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

```
##  104. 二叉树的最大深度
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```
## 78. 子集
```
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int depth, vector<int> &nums) {
        if (depth == nums.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[depth]);
        dfs(depth + 1, nums);
        cur.pop_back();
        dfs(depth + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(0, nums);
        return ans;
    }
};
```
## 15. 三数之和
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int k = n - 1;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (j < k && nums[j] + nums[k] > -nums[i]) k--;
                if (j == k) break;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};
```
## 149. 直线上最多的点数
```
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
```
## 1143. 最长公共子序列
```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                } else {
                    dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};
```
## 148. 排序链表
```
### 迭代
class Solution {
public:
    ListNode *getNode(ListNode *head, int num) {
        if (head == NULL) return NULL;
        ListNode *cur = head;
        while (--num && cur) {
            cur = cur->next;
        }
        if (cur == NULL) return cur;
        ListNode *ret = cur->next;
        cur->next = NULL;
        return ret;
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return ret->next;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *cur = head;
        int num = 0;
        while (cur) {
            num++;
            cur = cur->next;
        }
        for (int i = 1; i < num; i *= 2) {
            cur = ret->next;
            ListNode *tail = ret;
            while (cur) {
                ListNode *left = cur;
                ListNode *right = getNode(left, i);
                cur = getNode(right, i);
                tail->next = merge(left, right);
                while (tail->next) tail = tail->next;
            }
        }
        return ret->next;
    }
};
### 递归
class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *cur = head, *pre = head, *tail = head;
        while (tail && tail->next) {
            pre = cur;
            cur = cur->next;
            tail = tail->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(cur));
    }
};
```
## 297. 二叉树的序列化与反序列化
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ret;
        if (root == NULL) return ret;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *now = que.front();
            que.pop();
            if (now != NULL) {
                ret += to_string(now->val);
                que.push(now->left);
                que.push(now->right);
            } else ret += "null";
            ret += ',';
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() <= 2) return NULL;
        vector<string> cur;
        int len = 0, n = data.size();
        for (int i = 0; i < n; i++) {
            if (data[i] == ',') {
                cur.push_back(data.substr(i - len, len));
                len = 0;
            } else len++;
        }
        if (cur[0] == "null") return NULL;
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(stoi(cur[0]));
        TreeNode *temp = root;
        que.push(temp);
        int idx = 0;
        while (!que.empty()) {
            TreeNode *now = que.front();
            que.pop();
            if (++idx >= cur.size()) break;
            if (cur[idx] != "null") {
                now->left = new TreeNode(stoi(cur[idx]));
                que.push(now->left);
            }
            if (++idx >= cur.size()) break;
            if (cur[idx] != "null") {
                now->right = new TreeNode(stoi(cur[idx]));
                que.push(now->right);
            }
        }
        return root;
    }
};
```
## 1209. 删除字符串中的所有相邻重复项 II
```
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(make_pair(s[i], 1));
            } else {
                if (st.top().first == s[i]) {
                    if (st.top().second == k - 1) {
                        while (!st.empty() && st.top().first == s[i]) st.pop();
                    } else st.push(make_pair(s[i], st.top().second + 1));
                } else {
                    st.push(make_pair(s[i], 1));
                }
            }
        }
        string ret;
        while (!st.empty()) {
            ret += st.top().first;
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
## 155. 最小栈
```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while (!st.empty())st.pop();
        while (!st1.empty()) st1.pop();
    }

    void push(int x) {
        st.push(x);
        if (st1.empty()) st1.push(x);
        else {
            st1.push(min(st1.top(), x));
        }
    }

    void pop() {
        st.pop();
        st1.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st1.top();
    }

private:
    stack<int> st;
    stack<int> st1;
};
```
## 剑指 Offer 68 - II. 二叉树的最近公共祖先
```
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL) return root;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
```
## 889. 根据前序和后序遍历构造二叉树
```
class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode *solve(vector<int> &pre, vector<int> &post, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return NULL;
        TreeNode *head = new TreeNode(pre[L1]);
        if (L1 == R1) return head;
        int pos = mp[pre[L1 + 1]];
        int len = pos - L2 + 1;
        head->left = solve(pre, post, L1 + 1, L1 + len, L2, pos);
        head->right = solve(pre, post, L1 + len + 1, R1, pos + 1, R2 - 1);
        return head;
    }

    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        for (int i = 0; i < n; i++) mp[post[i]] = i;
        return solve(pre, post, 0, n - 1, 0, n - 1);
    }
};
```
## 102. 二叉树的层序遍历
```
class Solution {
public:
    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        return max(L, R) + 1;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        int dep = depth(root);
        vector<vector<int>> ret(dep);
        if (root == NULL) return ret;
        queue<pair<TreeNode *, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            pair<TreeNode *, int> now = que.front();
            que.pop();
            ret[now.second].push_back(now.first->val);
            if (now.first->left != NULL) que.push(make_pair(now.first->left, now.second + 1));
            if (now.first->right != NULL) que.push(make_pair(now.first->right, now.second + 1));
        }
        return ret;
    }
};

```
## 480. 滑动窗口中位数
```
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        multiset<int> st;
        for (int i = 0; i < k; i++) st.insert(nums[i]);
        multiset<int>::iterator it = next(st.begin(), k / 2);
        vector<double> ret;
        for (int i = k;; i++) {
            ret.push_back((1.0 * (*it) + *(next(it, k % 2 - 1))) * 0.5);
            if (i == nums.size()) break;
            st.insert(nums[i]);
            if (nums[i] < (*it)) it--;
            if (nums[i - k] <= (*it)) it++;
            st.erase(st.lower_bound(nums[i - k]));
        }
        return ret;
    }
} solve;
```
## 25. K 个一组翻转链表
```
class Solution {
public:

    pair<ListNode *, ListNode *> solve(ListNode *head, ListNode *tail) {
        ListNode *cur = head;
        ListNode *ret = tail->next;
        while (ret!=tail) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int num = 0;
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = head, *pre = hair;
        while (cur) {
            num++;
            if (num == k) {
                pair<ListNode *, ListNode *> ret = solve(pre->next, cur);
                pre->next = ret.first;
                cur = ret.second->next;
                pre = ret.second;
                num = 0;
            } else {
                cur = cur->next;
            }
        }
        return hair->next;
    }
};
```
## 91. 解码方法
```
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') dp[i + 1] += dp[i];
            if (i > 0 && s[i - 1] != '0') {
                int num = (s[i] - '0') + (s[i - 1] - '0') * 10;
                if (num <= 26 && num > 0) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[n];
    }
};

```
## 162. 寻找峰值
```
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int low = 0, high = nums.size() - 1, ans;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

```
## 1352. 最后 K 个数的乘积
```
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
```
## 31. 下一个排列
```
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int pos = nums.size() - 2;
        while (pos >= 0 && nums[pos + 1] <= nums[pos]) pos--;
        if (pos >= 0) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[pos]) {
                    swap(nums[i], nums[pos]);
                    break;
                }
            }
        }
        reverse(next(nums.begin(), pos + 1), nums.end());
    }
};
```

## 97. 交错字符串
```
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                int pos = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && (s1[i - 1] == s3[pos]));
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && (s2[j - 1] == s3[pos]));
                }
            }
        }
        return bool(dp[len1][len2]);
    }
};

```
## 328. 奇偶链表
```
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```
## 300. 最长上升子序列
```
class Solution {
public:
    int dp[100010];

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (!n) return 0;
        int len = 0;
        dp[len++] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[len - 1]) {
                dp[len++] = nums[i];
            } else {
                int pos = lower_bound(dp, dp + len, nums[i]) - dp;
                dp[pos] = nums[i];
            }
        }
        return len;
    }
};
```
## 3. 无重复字符的最长子串
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int len = s.size();
        int l = 0, r = 0, ans = 0;
        while (r < len) {
            if (mp[s[r]] == 1) {
                while (mp[s[r]] == 1) {
                    mp[s[l]]--;
                    l++;
                }
                mp[s[r]] = 1;
            } else {
                mp[s[r]] = 1;
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
```
## 剑指 Offer 51. 数组中的逆序对
```
class Solution {
public:
    int ans = 0;

    void merge(vector<int> &nums, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return;
        int temp[R2 - L1 + 1];
        int i = L1, j = L2, pos = 0;
        while (i <= R1 && j <= R2) {
            if (nums[i] <= nums[j]) {
                temp[pos++] = nums[i++];
            } else {
                ans += R1 - i + 1;
                temp[pos++] = nums[j++];
            }
        }
        while (i <= R1) temp[pos++] = nums[i++];
        while (j <= R2) temp[pos++] = nums[j++];
        for (int i = L1; i <= R2; i++) {
            nums[i] = temp[i - L1];
        }
    }

    void mergeSort(vector<int> &nums, int L, int R) {
        if (L >= R) return;
        int mid = (L + R) / 2;
        mergeSort(nums, L, mid);
        mergeSort(nums, mid + 1, R);
        merge(nums, L, mid, mid + 1, R);
    }

    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        ans = 0;
        mergeSort(nums, 0, n - 1);
        return ans;
    }
};
```

## 24. 两两交换链表中的节点
```
class Solution {
public:
    pair<ListNode *, ListNode *> solve(ListNode *head, ListNode *tail) {
        ListNode *ret = tail->next;
        ListNode *cur = head;
        while (ret != tail) {
            ListNode *temp = head->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return make_pair(tail, head);
    }

    ListNode *swapPairs(ListNode *head) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = head, *pre = hair;
        int num = 0;
        while (cur) {
            num++;
            if (num == 2) {
                auto ret = solve(pre->next, cur);
                pre->next = ret.first;
                pre = ret.second;
                cur = ret.second->next;
                num = 0;
            } else {
                cur = cur->next;
            }
        }
        return hair->next;
    }
};
```
## 34. 在排序数组中查找元素的第一个和最后一个位置
```
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        vector<int> ret;
        if (nums.size() == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (low == nums.size() || nums[low] != target) low = -1;
        ret.push_back(low);
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high < 0 || nums[high] != target) high = -1;
        ret.push_back(high);
        return ret;
    }
};

```
## 43. 字符串相乘
```
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
```

## 剑指 Offer 52. 两个链表的第一个公共节点
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while (curA != curB) {
            curA = curA != NULL ? curA->next : headB;
            curB = curB != NULL ? curB->next : headA;
        }
        return curA;
    }
};
```

## 496. 下一个更大元素 I
```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums2.size();
        vector<int> L(10010, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) st.push(nums2[i]);
            else {
                while (!st.empty() && st.top() <= nums2[i]) {
                    L[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        while (!st.empty()) {
            L[st.top()] = -1;
            st.pop();
        }
        vector<int> ret;
        for (int i = 0; i < nums1.size(); i++) {
            ret.push_back(L[nums1[i]]);
        }
        return ret;
    }
};
```

## 503. 下一个更大元素 II
```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        n *=2;
        vector<int> L(n + 1, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) st.push(i);
            else {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    L[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty()) {
            L[st.top()] = -1;
            st.pop();
        }
        vector<int> ret;
        for (int i = 0; i < n / 2; i++) ret.push_back(L[i]);
        return ret;
    }
};
```

## 剑指 Offer 11. 旋转数组的最小数字
```
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int low = 0, high = numbers.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numbers[mid] > numbers[high]) low = mid + 1;
            else if (numbers[mid] < numbers[high]) high = mid;
            else high--;
        }
        return numbers[low];
    }
};
```
## 134. 加油站
```
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, cur = 0, pos = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {
                pos = i + 1;
                cur = 0;
            }
        }
        return sum >= 0 ? pos : -1;
    }
};
```
## 670. 最大交换
```
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
```
## 622. 设计循环队列
```
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        head = tail = count = 0;
        num.resize(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == size) return false;
        count++;
        num[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) return false;
        head = (head + 1) % size;
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (count == 0) return -1;
        return num[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (count == 0) return -1;
        return num[(tail - 1 + size) % size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (count == 0) return true;
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (count == size) return true;
        return false;
    }

private:
    int size, head, tail, count;
    vector<int> num;
};

```
## 92. 反转链表 II
```
class Solution {
public:
    ListNode *solve(ListNode *head, ListNode *tail) {
        ListNode *ret = tail->next;
        ListNode *cur = head;
        while (ret != tail) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return ret;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *cur = hair->next, *pre = hair, *tail = head;
        int num = 0;
        while (cur) {
            num++;
            if (num == m - 1) {
                pre = cur;
            }
            if (num == n) {
                tail = cur;
            }
            cur = cur->next;
        }
        solve(pre->next, tail);
        pre->next = tail;
        return hair->next;
    }
};
```
## 143. 重排链表
```
class Solution {
public:
    ListNode *solve(ListNode *head) {
        ListNode *ret = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return ret;
    }

    void reorderList(ListNode *head) {
        ListNode *cur = head;
        int num = 0;
        while (cur) {
            num++;
            cur = cur->next;
        }
        num = (num + 2) / 2 + 1;
        cur = head;
        ListNode *mid, *pre;
        int pos = 0;
        while (cur) {
            pos++;
            if (pos == num) {
                pre->next = NULL;
                mid = cur;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        mid = solve(mid);
        cur = head;
        while (mid) {
            ListNode *temp1 = cur->next;
            ListNode *temp2 = mid->next;
            cur->next = mid;
            mid->next = temp1;
            cur = temp1;
            mid = temp2;
        }
    }
};

```
## 719. 找出第 k 小的距离对
```
class Solution {
public:
    int check(vector<int> &nums, int mid) {
        int L = 0, R, ret = 0;
        for (R = 0; R < nums.size(); R++) {
            while (nums[R] - nums[L] > mid) L++;
            ret += R - L;
        }
        return ret;
    }

    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back(), ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```
## 380. 常数时间插入、删除和获取随机元素
```
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        v.clear();
        mp.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mp.count(val)) return false;
        int idx = mp[val];
        mp[v.back()] = idx;
        swap(v[idx], v.back());
        v.pop_back();
        mp.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % (v.size())];
    }

private:
    vector<int> v;
    unordered_map<int, int> mp;
};

```
## 234. 回文链表
```
class Solution {
public:
    ListNode *solve(ListNode *head) {
        ListNode *ret = NULL;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = ret;
            ret = cur;
            cur = temp;
        }
        return ret;
    }

    bool isPalindrome(ListNode *head) {
        if (head == NULL) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *ret = solve(slow->next);
        ListNode *cur = head;
        while (ret) {
            if (ret->val != cur->val) return false;
            ret = ret->next;
            cur = cur->next;
        }
        return true;
    }
};
```
## 剑指 Offer 33. 二叉搜索树的后序遍历序列
```
class Solution {
public:
    struct node {
        int val;
        node *lson, *rson;

        node(int val) : val(val), lson(NULL), rson(NULL) {}
    };

    unordered_map<int, int> mp;

    node *build(vector<int> &inorder, vector<int> &postorder, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return NULL;
        int pos = mp[postorder[R2]];
        if (pos > R1 || pos < L1) return NULL;
        node *head = new node(postorder[R2]);
        head->lson = build(inorder, postorder, L1, pos - 1, L2, L2 + pos - L1 - 1);
        head->rson = build(inorder, postorder, pos + 1, R1, L2 + pos - L1, R2 - 1);
        return head;
    }

    bool check(node *head) {
        if (head == NULL) return true;
        node *cur = head;
        if (cur->lson) {
            if (cur->lson->val > head->val) return false;
        }
        if (cur->rson) {
            if (cur->rson->val < head->val) return false;
        }
        bool ret = (check(cur->lson) && check(cur->rson));
        return ret;
    }

    int getNum(node *head) {
        if (head == NULL) return 0;
        return getNum(head->lson) + 1 + getNum(head->rson);
    }

    bool verifyPostorder(vector<int> &postorder) {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        mp.clear();
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        node *head = build(inorder, postorder, 0, n - 1, 0, n - 1);
        int num = getNum(head);
        if (num != n) return false;
        return check(head);
    }
};

```