class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited){
        visited[i] = true;

        for(int node : adj[i]){
            if(!visited[node]){
                dfs(node, adj, visited);
            }
        }

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1!=edges.size()){
            return false;
        }
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        dfs(0, adj, visited);
        for(bool tf : visited){
            if(!tf){
                return false;
            }
        }

        return true;
        
    }
};
