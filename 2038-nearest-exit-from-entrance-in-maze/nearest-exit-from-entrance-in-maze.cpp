class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        //{{row,col}, step}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int eRow = entrance[0];
        int eCol = entrance[1];
        q.push({{eRow, eCol}, 0});
        vis[eRow][eCol] = true;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        while (!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;
            int steps = p.second;

            // check for boundary cell
            if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                (row != eRow || col != eCol)) {
                return steps;
            }

            for (int i = 0; i < 4; i++) {
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] &&
                    maze[nr][nc] == '.') {
                    q.push({{nr, nc}, steps + 1});
                    vis[nr][nc] = true;
                }
            }
        }
        return -1;
    }
};