#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class FoodRatings {
public:
    map< string, pair<string, int>>mpp;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            // mpp[{foods[i],cuisines[i]}] = ratings[i];
            mpp[foods[i]] = {cuisines[i], ratings[i]};
        }
    }

    void changeRating(string food, int newRating) {
        auto mppFood = mpp[food];
        mppFood.second  = newRating;
        mpp[food] = mppFood;
    }

    string highestRated(string cuisine) {
        int rat = -1;
        string s;
        for (auto it : mpp) {
            if (it.second.first == cuisine) {
                if (rat < it.second.second) {
                    rat = it.second.second;
                    s = it.first;
                }
            }
        }
        return s;
    }
};


