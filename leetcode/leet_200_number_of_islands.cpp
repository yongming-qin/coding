





class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        nRow = grid.size(); nCol = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0;j < nCol; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int,int>> qu;
        qu.push({i,j}); grid[i][j] = '0';
        
        while (qu.size()) {
            auto cur = qu.front(); qu.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = cur.first + dirs[k][0];
                int nj = cur.second + dirs[k][1];
                if (ni >= 0 && ni < nRow && nj >= 0 && nj < nCol && grid[ni][nj] == '1') {
                    qu.push({ni,nj});
                    grid[ni][nj] = '0'; // Important. avoid repeatation
                }
            }
        }
    }
    
    
    int dirs[4][2] = {-1,0, 1,0, 0,-1, 0,1};
    int nRow, nCol;
};