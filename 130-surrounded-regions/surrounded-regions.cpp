class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& board,int r,
             int c) {
        board[r][c]='s';

        for (int i = 0; i < 4; i++) {
            int nr = r + delr[i];
            int nc = c + delc[i];
            if (nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O') {
                dfs(board, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<n;i++){
            //first row
            if(board[0][i]=='O'){
                dfs(board, 0,i);
            }
            //last row
            if(board[m-1][i]=='O'){
                dfs(board, m-1, i);
            }
        }
        for(int i=0;i<m;i++){
            //first col
            if(board[i][0]=='O'){
                dfs(board, i,0);
            }
            //last col
            if(board[i][n-1]=='O'){
                dfs(board, i,n-1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }else if(board[i][j]=='s'){
                    board[i][j]='O';
                }
            }
        }
    }
};