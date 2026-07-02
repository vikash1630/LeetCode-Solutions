class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        // Health remaining after standing on the starting cell
        int startHealth = health - grid[0][0];

        // If we die immediately
        if (startHealth <= 0)
            return false;

        // best[r][c] = maximum health remaining when reaching (r,c)
        vector<vector<int>> best(n, vector<int>(m, -1));
        best[0][0] = startHealth;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Destination reached with positive health
            if (r == n - 1 && c == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundaries
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Health left after entering neighbour
                int newHealth = best[r][c] - grid[nr][nc];

                // Cannot move if health becomes 0 or negative
                if (newHealth <= 0)
                    continue;

                // Already reached this cell with better or equal health
                if (newHealth <= best[nr][nc])
                    continue;

                // Update best health and continue BFS
                best[nr][nc] = newHealth;
                q.push({nr, nc});
            }
        }

        return false;
    }
};