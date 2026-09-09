class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited){
        if(!visited[i]){
            visited[i] = true;
        }

        for(int neigh:adj[i]){
            if(visited[neigh]){
                continue;
            }
            dfs(neigh, adj, visited);
        }
    }



    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(vector<int> it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < visited.size(); i++){
            if(!visited[i]){
                components++;
                dfs(i, adj, visited);
            }
        }

        return components;

    }
};
