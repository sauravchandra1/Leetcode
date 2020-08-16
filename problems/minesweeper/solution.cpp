class Solution {
    int rows,cols;
    int X[8] = {0,-1,-1,-1,0,1,1,1};
    int Y[8] = {1,1,0,-1,-1,-1,0,1};
    int countMines(vector<vector<char>>& board,int x,int y){
        int count = 0;
        for(int i=0;i<8;i++){
            int dx = x + X[i], dy = y + Y[i];
            if(dx>=0 && dy>=0 && dx<rows && dy<cols && board[dx][dy]=='M')
                count++;
        }
        return count;
    }
    void dfs(vector<vector<char>>& board,int x, int y){
        
        int mines = countMines(board,x,y);
        if(mines == 0)
            board[x][y] = 'B';
        else{
            board[x][y] = char(mines+'0');
            return;
        }
        for(int i=0;i<8;i++){
            int dx = x + X[i], dy = y + Y[i];
            if(dx>=0 && dy>=0 && dx<rows && dy<cols && board[dx][dy]=='E')
                dfs(board,dx,dy);
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size()==0 || board[0].size()==0)
            return board;
        rows = board.size(); cols = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y] == 'M')
            board[x][y] = 'X';
        else if(board[x][y] == 'E')
            dfs(board,x,y);
        return board;
    }
};