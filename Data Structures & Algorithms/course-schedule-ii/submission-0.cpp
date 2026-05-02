class Solution {
public:

    bool iscycle(int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& edge) {
        vis[src] = true;
        rec[src] = true;

        for(int i = 0; i < edge.size(); i++){
            int u = edge[i][1];
            int v = edge[i][0];

            if(src == u){
                if(!vis[v]){
                    if(iscycle(v, vis, rec, edge))
                        return true;
                } 
                else if(rec[v]){
                    return true;
                }
            }
        }

        rec[src] = false;
        return false;
    }

    void topo(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& edge) {
        vis[src] = true;

        for(int i = 0; i < edge.size(); i++){
            int u = edge[i][1];
            int v = edge[i][0];

            if(src == u && !vis[v]){
                topo(v, vis, s, edge);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        vector<int> ans;

        // Cycle check
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(iscycle(i, vis, rec, edge)){
                    return ans;  // empty, cycle exists
                }
            }
        }

        // Topological sort
        vis.assign(n, false);
        stack<int> s;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topo(i, vis, s, edge);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};