#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

int main() {
    HashMap mp;
    mp.put(123, 1);
    mp.put(123123, 2);
    mp.put(111, 3);
    mp.put(222, 4);
    cout << mp.get(123) << endl;
    cout << mp.get(123123) << endl;
    cout << mp.get(111) << endl;
    cout << mp.get(222) << endl;
    return 0;
}
