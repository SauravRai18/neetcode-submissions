class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it: times){

            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        vector<int> dis(n+1, INT_MAX);

        dis[k] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});

        while(!pq.empty()){

            int d = pq.top().first;

            int u = pq.top().second;

            pq.pop();

            if( d > dis[u]){
                continue;
            }

            for(auto &it : adj[u]){

                if(dis[it.first] > dis[u] + it.second){

                    dis[it.first] = dis[u] + it.second;

                    pq.push({dis[it.first], it.first});
                }


            }
        }

        int ans = 0;

        for(int i =1; i<=n; i++){

            if(dis[i] == INT_MAX){
                return -1;
            }

            else{

                ans = max(ans, dis[i]);
            }
        }
        return ans;
    }
};
