#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            um[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (pair<string, vector<string>> ps : um) {
            result.push_back(ps.second);
        }
        return result;
    }
};