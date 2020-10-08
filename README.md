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
## 912. 排序数组(堆排序)
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
class SmartPtr;
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
    return pdst;
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