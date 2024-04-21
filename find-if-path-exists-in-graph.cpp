/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;
        vector<bool> visited(n, false);
        visited[source] = true;
        bool flag = true;
        while (flag) {
            flag = false;
            for (const auto& edge : edges) {
                if (visited[edge[0]] != visited[edge[1]]) {
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    flag = true;
                }
                if (visited[destination]) return true;
            }
        }
        return false;
    }
};