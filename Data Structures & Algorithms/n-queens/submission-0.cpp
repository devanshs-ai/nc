class Solution {
public:
    int n;
    vector<vector<string>> res;
    vector<int>col;
    vector<int>pos;
    vector<int>neg;

    void backtrack(vector<string>&board, int row){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            if(col[i] || pos[row+i] || neg[row-i+n-1]){
                continue;
            }

            board[row][i] = 'Q';
            col[i] = 1;
            pos[row+i] = 1;
            neg[row-i+n-1] = 1;

            backtrack(board, row+1);

            board[row][i] = '.';
            col[i] = 0;
            pos[row+i] = 0;
            neg[row-i+n-1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        col.resize(n, 0);
        pos.resize(2*n-1, 0);
        neg.resize(2*n-1, 0);

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0);

        return res;
    }
};
