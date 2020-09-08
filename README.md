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