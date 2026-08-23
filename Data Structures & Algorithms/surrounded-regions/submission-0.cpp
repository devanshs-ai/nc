class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>>q;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if((i==0||j==0||i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='O'){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow>=0 && nrow<board.size()-1 && ncol>=0 && ncol < board[0].size()-1 && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
