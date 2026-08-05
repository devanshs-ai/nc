class Solution {
public:
    bool helper(vector<vector<char>>&board, int k){
        unordered_map<char, int>mpp;
        for(int i = k; i < k+3; i++){
            for(int j = k; j < k+3; j++){
                if(mpp.find(board[i][j])!=mpp.end() && ((board[i][j]-'0')<=9 && (board[i][j]-'0')>=1)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++){
            unordered_map<char, int>mpp;
            for(int j = 0; j < board[0].size(); j++){
                if(mpp.find(board[i][j])!=mpp.end() && ((board[i][j]-'0')<=9 && (board[i][j]-'0')>=1)){
                    return false;
                }
                mpp[board[i][j]]++;
            }
        }

        for(int i = 0; i < board[0].size(); i++){
            unordered_map<char, int>mpp;
            for(int j = 0; j < board.size(); j++){
                if(mpp.find(board[j][i])!=mpp.end() && ((board[j][i]-'0')<=9 && (board[j][i]-'0')>=1)){
                    return false;
                }
                mpp[board[j][i]]++;
            }
        }

        unordered_map<char, int>mpp;
        unordered_map<char, int>mp;
        for(int i = 0; i < board.size(); i++){
            if(i%3==0){
                mpp = mp;
            }
            for(int j = 0; j < 3; j++){
                if(mpp.find(board[i][j])!=mpp.end() && ((board[i][j]-'0')<=9 && (board[i][j]-'0')>=1)){
                    return false;
                }
                mpp[board[i][j]]++;                
            }
        }

        mpp = mp;
        for(int i = 0; i < board.size(); i++){
            if(i%3==0){
                mpp = mp;
            }
            for(int j = 3; j < 6; j++){
                if(mpp.find(board[i][j])!=mpp.end() && ((board[i][j]-'0')<=9 && (board[i][j]-'0')>=1)){
                    return false;
                }
                mpp[board[i][j]]++;                
            }
        }

        mpp=mp;
        for(int i = 0; i < board.size(); i++){
            if(i%3==0){
                mpp = mp;
            }
            for(int j = 6; j < 9; j++){
                if(mpp.find(board[i][j])!=mpp.end() && ((board[i][j]-'0')<=9 && (board[i][j]-'0')>=1)){
                    return false;
                }
                mpp[board[i][j]]++;                
            }
        }

        return true;


    }
};
