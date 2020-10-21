
#include <bits/stdc++.h>

using namespace std;

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

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {

    return 0;
}