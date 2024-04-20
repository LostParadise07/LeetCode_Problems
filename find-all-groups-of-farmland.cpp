/*
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
*/
class Solution {
public:
    void solve(int r, int c, int &r2, int &c2, vector<vector<int>>& land, vector<vector<int>>& vis) {
        int m = land.size();
        int n = land[0].size();
        
        vis[r][c] = 1;
        
        int dp1[4] = {-1, 1, 0, 0};
        int dp2[4] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = dp1[i] + r; // New row
            int nc = dp2[i] + c; // New column
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && land[nr][nc] == 1 && !vis[nr][nc]) {
                // Updating the maximum row and column encountered so far
                r2 = max(r2, nr);
                c2 = max(c2, nc);
                
                // Recursively exploring the farmland
                solve(nr, nc, r2, c2, land, vis);
            }
        }
    }
    
    // Main function to find all farmland
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // Getting the dimensions of the land
        int m = land.size();
        int n = land[0].size();
        
        // Creating a 2D array to mark visited cells
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // Vector to store the coordinates of each farmland
        vector<vector<int>> ans;
        
        // Iterating through each cell in the land
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is unvisited and is part of farmland
                if (!vis[i][j] && land[i][j] == 1) {
                    int r2 = i, c2 = j; // Initialize maximum row and column
                    
                    // Recursive function to explore and mark the farmland
                    solve(i, j, r2, c2, land, vis);
                    
                    // Pushing the coordinates of the farmland into the result vector
                    ans.push_back({i, j, r2, c2});
                }
            }
        }
        
        // Returning the vector containing coordinates of all farmland
        return ans;
    }
};