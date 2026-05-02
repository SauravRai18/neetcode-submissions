class Solution {
public:


    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m){


        if(i <0 || j<0 || i>=n || j >= m || vis[i][j] || grid[i][j] != 1){
            return 0;
        }



        vis[i][j] = true;

        int area = 1;
        area +=dfs(grid, vis, i+1, j, n, m);
        area +=dfs(grid, vis, i-1, j, n, m);
        area +=dfs(grid, vis, i, j + 1, n, m);
        area +=dfs(grid, vis, i, j-1, n, m);


        return area;


    }




    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){

                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = dfs(grid, vis, i, j, n, m);

                    maxArea = max(maxArea, area);

                }
            }
        }

        return maxArea;



        
    }
};
