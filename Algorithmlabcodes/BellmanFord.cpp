class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int n = edges.size();
        vector<int>dis(V,1e8);
        dis[src] = 0;
        for(int j = 0;j<V-1;j++){
            for(int i =0;i<n;i++){
                int des = edges[i][1],w = edges[i][2];
                int s = edges[i][0];
                if(dis[s] != 1e8 && dis[des] > dis[s] + w){
                    dis[des] = dis[s] + w;
                }
            }
        }
          // Detect reachable negative cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                return {-1};
            }
        }
        return dis;
    }
};
