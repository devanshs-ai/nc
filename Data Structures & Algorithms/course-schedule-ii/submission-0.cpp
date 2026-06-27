class Solution {
public:
    bool dfs(vector<int>& visited, vector<vector<int>>& adj, vector<int>& res, int i){
        visited[i] = 1;
        
        for(int it : adj[i]){
            if(visited[it]==0){
                if(!dfs(visited, adj, res, it)){
                    return false;
                }
            }
            else if(visited[it]==1){
                return false;
            }
        }

        visited[i] = 2;
        res.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>visited(numCourses, 0);
        vector<int>res;
        for(auto& pre : prerequisites){
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i]==0){
                if(!dfs(visited, adj, res, i)){
                    return {};
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
