#include <bits/stdc++.h>

using namespace std;

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

int main() {

    return 0;
}