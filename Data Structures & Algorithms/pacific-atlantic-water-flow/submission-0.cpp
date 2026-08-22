class Solution {
public:

    void bfs(vector<vector<int>>&graph, queue<pair<int, int>>&q, vector<vector<bool>>& visited){
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i <= 3; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow>=0 && nrow<graph.size() && ncol>=0 && ncol < graph[0].size() && graph[nrow][ncol]>=graph[row][col] && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //reverse bfs
        //i thought maybe we could take every cell and then run a loop through it to find
        //if there is any other cell greater than it if yes stop, if no go ahead
        //but instead we can do something else that is, water to cell whichever is lower for it to enter

        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        queue<pair<int, int>>pacificq;
        queue<pair<int, int>>atlanticq;

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i==0 || j==0){
                    pacific[i][j] = true;
                    pacificq.push({i, j});
                }
                if(i==heights.size()-1 || j==heights[0].size()-1){
                    atlantic[i][j] = true;
                    atlanticq.push({i, j});
                }
            }
        }

        bfs(heights, pacificq, pacific);
        bfs(heights, atlanticq, atlantic);

        vector<vector<int>> res;

        for(int i = 0; i < heights.size(); i++){

            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
     
        }

        return res;
    }
};
