/*
You are given the array paths, where paths[i] = [cityAi, cityBi] 
means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, 
therefore, there will be exactly one destination city.

*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>pre;
        set<string>post;
        for(auto it:paths){
            pre.insert(it[0]);
            post.insert(it[1]);
        }
        for(auto it:post){
            if(pre.find(it)==pre.end()) return it;
        }
        return "";
    }
};