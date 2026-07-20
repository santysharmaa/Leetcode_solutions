class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int oldPos = i * n + j;
                int newPos = (oldPos + k) % total;

                ans[newPos / n][newPos % n] = grid[i][j];
            }
        }

        return ans;
    }
};