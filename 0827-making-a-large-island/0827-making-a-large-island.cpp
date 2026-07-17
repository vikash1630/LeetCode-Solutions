class DisJointset {
public:
    vector<int> parent, size;

    DisJointset(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUlp(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUlp(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int Ulp_u = findUlp(u);
        int Ulp_v = findUlp(v);

        if (Ulp_u == Ulp_v)
            return;

        if (size[Ulp_u] < size[Ulp_v]) {
            parent[Ulp_u] = Ulp_v;
            size[Ulp_v] += size[Ulp_u];
        }
        else {
            parent[Ulp_v] = Ulp_u;
            size[Ulp_u] += size[Ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        DisJointset dis(n * n);

        // ==========================
        // STEP 1 : Build all islands
        // ==========================

        // ❌ Your mistake:
        // for(auto &it : grid)
        // Grid stores VALUES, not coordinates.
        // We must iterate using row and col.

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                // Ignore water
                if (grid[row][col] == 0)
                    continue;

                // ❌ Your mistake:
                // row + n + col
                // Correct mapping:
                int curPos = row * n + col;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    // ❌ Your mistake:
                    // You were unioning even if neighbour was water.

                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {

                        int adjPos = nr * n + nc;

                        dis.UnionBySize(curPos, adjPos);
                    }
                }
            }
        }

        int ans = 0;

        // ==========================================
        // STEP 2 : Convert every 0 into 1 and check
        // ==========================================

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                // Already land
                if (grid[row][col] == 1)
                    continue;

                set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {

                        int adjPos = nr * n + nc;

                        components.insert(dis.findUlp(adjPos));
                    }
                }

                int total = 1;

                // Add sizes of all unique neighbouring islands
                for (auto parent : components) {
                    total += dis.size[parent];
                }

                ans = max(ans, total);
            }
        }

        // ======================================
        // STEP 3 : Handle all-1 grid
        // ======================================

        // ❌ Your code missed this case.
        // Example:
        // 1 1
        // 1 1
        // Answer should be 4.

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) {

                    int node = row * n + col;

                    ans = max(ans, dis.size[dis.findUlp(node)]);
                }
            }
        }

        return ans;
    }
};