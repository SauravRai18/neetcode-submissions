class Solution {
public:

    bool dfs(int src, int des,  vector<bool>& vis, vector<vector<int>>& adj ){

        if(src == des){
            return true;
        }

        vis[src] = true;

        for(auto neigh : adj[src]){
            if(!vis[neigh]){
                if(dfs( neigh, des, vis,  adj)){
                     return true;

                }
               

            }
        }
        return false;

    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n+1);

        for(auto &x : edges){

            int u = x[0];
            int v = x[1];

            vector<bool> vis(n+1, false);

            if(dfs(u, v, vis, adj)){
                return x;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);



        }
        return {};
        
    }
};
