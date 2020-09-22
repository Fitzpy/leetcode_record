#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main() {

    return 0;
}
