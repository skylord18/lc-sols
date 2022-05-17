#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class LRUCache {
    map<int, int> mpp;
    map<int, list<int>:: iterator> address;
    int cap;
    int size;
    list<int>ls;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    int get(int key) {
        if (mpp.find(key) == mpp.end())return -1;
        list<int> :: iterator it = address[key];
        ls.erase(it);
        address.erase(key);
        ls.push_front(key);
        address[key] = ls.begin();
        return mpp[key];
    }
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            list <int> :: iterator toDelete = address[key];
            ls.erase(toDelete);
            mpp.erase(key);
            address.erase(key);
            size--;
        }
        if (size == cap) {
            int k = ls.back();
            ls.pop_back();
            address.erase(k);
            mpp.erase(k);
            size--;
        }
        size++;
        ls.push_front(key);
        address[key] = ls.begin();
        mpp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */