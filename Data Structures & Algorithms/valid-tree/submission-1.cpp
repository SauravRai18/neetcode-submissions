class Solution {
public:


    void dfs(int src, vector<vector<int>>& graph, vector<bool>& vis){
        vis[src] = true;

        for(int v : graph[src]){
            if(!vis[v]){
                dfs(v, graph, vis);
            }
        }
    }



    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1){
            return false;
        }

           vector<vector<int>> graph(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        dfs(0, graph, vis);

        for(bool e : vis){
            if(!e){
                return false;
            }
        }

        return true;

    }
};
