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

