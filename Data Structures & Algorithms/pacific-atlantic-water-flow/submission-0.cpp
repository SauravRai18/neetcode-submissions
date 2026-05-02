class Solution {
public:

    void bfs( queue<pair<int, int>> &q,  vector<vector<bool>>& vis, vector<vector<int>>& heights, int m, int n ){

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            if(i-1 >= 0 && !vis[i-1][j] && heights[i-1][j] >= heights[i][j]){
                vis[i-1][j] = true;
                q.push({i-1, j});
                
            }

              if(i+1 < m && !vis[i+1][j] && heights[i+1][j] >= heights[i][j]){
                vis[i+1][j] = true;
                q.push({i+1, j});
                
            }

              if(j-1 >= 0 && !vis[i][j-1] && heights[i][j-1] >= heights[i][j]){
                vis[i][j-1] = true;
                q.push({i, j-1});
                
            }

               if(j+1 < n && !vis[i][j+1] && heights[i][j+1] >= heights[i][j]){
                vis[i][j+1] = true;
                q.push({i, j+1});
                
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false)); 

        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;

        for(int i= 0; i<m; i++){
            qp.push({i, 0});
            pac[i][0] = true;
        }

        for(int j =0; j<n; j++){
            qp.push({0, j});
            pac[0][j] = true;
        }

//atlantic

        for(int i= 0; i<m; i++){
            qa.push({i, n-1});
            atl[i][n-1] = true;
        }

        for(int j =0; j<n; j++){
            qa.push({m-1, j});
            atl[m-1][j] = true;
        }

        bfs(qp, pac, heights, m, n);
        bfs(qa, atl, heights, m, n);


        vector<vector<int>> ans;

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac[i][j] && atl[i][j] ){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;


    }
};
