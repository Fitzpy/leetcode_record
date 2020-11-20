#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        map<int, int> mp1, mp2;
        for (int i = 0; i < arr1.size(); i++) {
            mp1[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            mp2[arr2[i]]++;
        }
        vector<int> ret;
        vector<int> cur;
        for (int i = 0; i < arr2.size(); i++) {
            if (mp1.count(arr2[i])) {
                for (int j = 0; j < mp1[arr2[i]]; i++) ret.push_back(arr2[i]);
            }
        }
        for (int i = 0; i < arr1.size(); i++) {
            if (!mp2.count(arr1[i])) cur.push_back(arr1[i]);
        }
        sort(cur.begin(), cur.end());
        for (int i = 0; i < cur.size(); i++) ret.push_back(cur[i]);
        return ret;
    }
};

int main() {

    return 0;
}