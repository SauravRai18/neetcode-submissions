class Solution {
public:

    bool dfs(int i, int j, int t, vector<vector<bool>>& vis, vector<vector<int>>& grid ){

        int n = grid.size();


        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] > t){
            return false;
        }


        if(i == n - 1 && j == n - 1){
            return true;
        }

        vis[i][j] = true;

        return dfs(i+1, j, t, vis, grid)||
        dfs(i-1, j, t, vis, grid)||
        dfs(i, j+1, t, vis, grid)||
        dfs(i, j-1, t, vis, grid);

    }


    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        int start = grid[0][0];

        int end = n * n - 1;

        while(start < end){
            int mid = start + (end - start) / 2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if(dfs(0,0, mid, vis, grid)){

                end = mid;
            }else {

                start = mid + 1;
            }


        }

        return start;

     



        
    }
};
