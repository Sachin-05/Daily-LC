class Solution {
public:
    int m,n;
    vector <vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<bool>> &visited){
        if(visited[i][j]){
            return true;
        }
        visited[i][j] = true;
        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(ni>=0 && nj>=0 && ni<m && nj<n && grid[i][j]==grid[ni][nj]){
                if(ni==pi && nj==pj){
                    continue;
                }

                if(dfs(ni,nj,i,j,grid,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        // detecting a cycle in a undirected graph using dfs
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(!visited[i][j]){
                    if(dfs(i,j,i,j,grid, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
