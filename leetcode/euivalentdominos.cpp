#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<pair<int, int>, int> count;
    int result = 0;

    for (const auto& domino : dominoes) {
        int a = domino[0], b = domino[1];
        pair<int, int> key = {min(a, b), max(a, b)};
        result += count[key];  
        count[key]++;          
    }

    return result;
}
