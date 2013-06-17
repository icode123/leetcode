class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solve(board,0,0);
    }
       bool solve(vector<vector<char> > &board, int row, int col) {
        bool res = getNextEmpty(board, row, col);
        if (!res) return true;
        vector<char> possible;
        getPossibleValues(board, possible, row, col);
        if (possible.size() == 0) return false;
        for (size_t i = 0; i < possible.size(); i++) {
            board[row][col] = possible[i];
            if (solve(board, row, col)) return true;
            board[row][col] = '.';
        }
        return false;
    }

    bool getNextEmpty(vector<vector<char> > &board, int &row, int &col) {
        while (row <= 8 && col <= 8) {
            if (board[row][col] == '.') return true;
            row = (col == 8) ? row + 1 : row;
            col = (col == 8) ? 0 : col + 1;
        }
        return false;
    }

    void getPossibleValues(vector<vector<char> > &board, vector<char> &possible, int row, int col) {
        bool s[9] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') s[board[row][i]-'1'] = true;
            if (board[i][col] != '.') s[board[i][col]-'1'] = true;
            char c = board[row/3*3+i/3][col/3*3+i%3];
            if (c!='.') s[c-'1'] = true;
        }
        for (int i = 0; i < 9; i++) {
            if (!s[i]) possible.push_back('1'+i);
        }
    }
};

class Solution {
public:
    bool isValid(vector<vector<char> > &board, int x, int y)  
    {  
        int i,j;
        for(i=0;i<9;i++)
           if(i!=x && board[i][y]==board[x][y])
           return false;
        for(j=0;j<9;j++)
           if(j!=y && board[x][j]==board[x][y])
           return false;
        for(i=3*(x/3);i<3*(x/3+1);i++)
           for(j=3*(y/3);j<3*(y/3+1);j++)
           if(i!=x && j!=y && board[i][j]==board[x][y])
           return false;
        return true;
    }  

    bool solveSudoku(vector<vector<char> > &board) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < 9; ++i)  
            for (int j = 0; j < 9; ++j)  
            {  
                if ('.' == board[i][j])  
                {  
                    for (int k = 1; k <= 9; ++k)  
                    {  
                        board[i][j] = '0' + k;  
                        if (isValid(board, i, j) && solveSudoku(board))  
                            return true;  
                        board[i][j] = '.';  
                    }  
                    return false;  
                }  
            }  
        return true;  
    }
};

class Solution {
public:
    bool check(int x,int y,vector<vector<char> > &board)
    {
        bool flag[9]={false};
        for(int i=0;i<9;i++)
            if(board[x][i]!='.')
            {
                if(!flag[board[x][i]-'1']) flag[board[x][i]-'1']=true;
                else return false;
            }
        memset(flag,false,sizeof(flag));
        for(int i=0;i<9;i++)
            if(board[i][y]!='.')
            {
                if(!flag[board[i][y]-'1']) flag[board[i][y]-'1']=true;
                   else return false;
            }
        memset(flag,false,sizeof(flag));
        int xx=x/3*3;
        int yy=y/3*3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            if(board[xx+i][yy+j]!='.')
            {
                if(!flag[board[xx+i][yy+j]-'1']) flag[board[xx+i][yy+j]-'1']=true;
                   else return false;
            }    
        return true;
    }
    bool dfs(vector<vector<char> > &board)
    {
        for(int i=0;i<9;i++)
           for(int j=0;j<9;j++)
           {
               if(board[i][j]=='.')
               {
                   for(int k='1';k<='9';k++)
                   {
                       board[i][j]=k;
                       if(check(i,j,board) && dfs(board)) return true;
                       board[i][j]='.';
                   }
                   return false;
               }
           }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs(board);
    }
};





