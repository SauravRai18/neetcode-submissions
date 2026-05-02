class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;

            q.pop();


            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j] == 2147483647){
                grid[i-1][j] = grid[i][j] + 1;
                  q.push({i-1,j});
                vis[i-1][j] = true;
            }

              if(i+1 < m && !vis[i+1][j] && grid[i+1][j] == 2147483647){
                grid[i+1][j] = grid[i][j] + 1;
                q.push({i+1,j});
                vis[i+1][j] = true;
            }

             if(j -1 >=0 && !vis[i][j-1] && grid[i][j-1] == 2147483647){
                grid[i][j-1] = grid[i][j] + 1;
                  q.push({i,j-1});
                vis[i][j - 1] = true;
            }

            if(j+1 < n && !vis[i][j+1] && grid[i][j+1] == 2147483647){
                grid[i][j+1] = grid[i][j] + 1;
                  q.push({i,j+1});
                vis[i][j+1] = true;
            }


        }

        
    }
};
