/*
There are n cities connected by some number of flights. You are given an array flights 
where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city 
fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from 
src to dst with at most k stops. If there is no such route, return -1.
*/
class Solution {
public:
  
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
    
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>visited(n,INT_MAX);
        visited[src]=0;
        for(const auto& x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        int count=0;
        queue<pair<int,int>>qu;
        qu.push({src,0});
        K++;  
        while(K--){
            int size=qu.size();
            while(size--){
                int curr_price=qu.front().second;
                for(auto& x:adj[qu.front().first]){
                    int new_price=x.second+curr_price;
                    if(new_price<visited[x.first]){
                        visited[x.first]=new_price;
                        qu.push({x.first,new_price});
                    }
                }
                qu.pop();
            }
            count++;
        }
        return (visited[dst]==INT_MAX)?-1:visited[dst];
    }
};