class Solution {
public:
    void DFS(vector<vector<char> > &board, int i, int j)
    {
        if(i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j] != 'O') return;
            board[i][j] = '#';
            DFS(board, i-1, j);  // to left
            DFS(board, i+1, j);  // to right
            DFS(board, i, j-1);  // to up
            DFS(board, i, j+1);  // to down
    }

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(board.empty()||board[0].empty()) return;
        
        int m=board.size();
        int n=board[0].size();  // one row length
        
        for(int i = 1; i < m-1; i++){
            DFS(board, i, 0);        // left
            DFS(board, i, n-1);    // right
        }
        
        for(int j = 0; j < n; j++){
            DFS(board, 0, j);        // up
            DFS(board, m-1, j);    // down
        }
        
        //change 'O' to 'X'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
