/*

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving 
one unit north, south, east, or west, respectively. You start at the origin (0, 0) on 
a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on 
a location you have previously visited. Return false otherwise.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct pair_hash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};

        unordered_map<pair<int, int>, bool, pair_hash> mp; 

        bool isPathCrossing(string path) {
        pair<int, int> p = {0, 0};
        
        for (int i = 0; i < path.length(); i++) {
            
            mp[p] = true;
            if (path[i] == 'N') {
                p.second++;
            } else if (path[i] == 'S') {
                p.second--;
            } else if (path[i] == 'E') {
                p.first++;
            } else {
                p.first--;
            }
            if (mp[p] == true) return true;
        }
        return false;
    }
};