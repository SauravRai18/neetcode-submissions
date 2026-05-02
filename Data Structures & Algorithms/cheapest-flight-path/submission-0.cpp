class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;


        for(int i =0; i<=k; i++){

            vector<int> temp = dist;

            for(auto &it : flights){

                int u = it[0];
                int v = it[1];
                int price = it[2];

                if(dist[u] == INT_MAX) continue;

                temp[v] = min(temp[v], dist[u] + price);
            }

            dist = temp;
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];

        
    }
};
