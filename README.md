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