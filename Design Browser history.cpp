#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class BrowserHistory {
public:
    list<string> ls;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        ls.push_back(homepage);
        it = ls.begin();
    }

    void visit(string url) {
        auto del = it;
        del++;
        ls.erase(del, ls.end());
        ls.push_back(url);
        it++;
    }

    string back(int steps) {
        while (it != ls.begin() && steps--) {
            it--;
        }
        return *it;
    }

    string forward(int steps) {
        while (it != (--ls.end()) && steps--) {
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */