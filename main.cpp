#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, cur = 0, pos = -1;
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

int main() {

    return 0;
}