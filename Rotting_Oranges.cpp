class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int freshOranges = 0;
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) {
            return 0;
        }
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto temp = q.front();
                q.pop();
                int x = temp.first, y = temp.second;
                for (int i = 0; i < 4; ++i) {
                    int X = x + dx[i], Y = y + dy[i];
                    if (X >= 0 && X < n & Y >= 0 && Y < m && grid[X][Y] == 1) {
                        --freshOranges;
                        grid[X][Y] = 2;
                        q.push({X, Y});
                    }
                }
            }
            ++time;
        }
        if (freshOranges > 0) {
            return -1;
        }
        return time - 1;
    }
};