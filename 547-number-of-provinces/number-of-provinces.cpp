class Solution {
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        if(vis[node]) return;
        vis[node] = 1;
        for(auto it: adj[node]) dfs(it, adj, vis);
    }
public:
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> adj[n+1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && g[i][j]) {
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<int> vis(n+1, 0);
        vis[0] = 1;

        int cnt = 0;
        for(int i = 0; i <= n; i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};