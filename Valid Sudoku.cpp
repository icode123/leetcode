class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=board.size();
        if(!m) return false;
        int n=board[0].size();
        if(!n) return false;
        if(m%3||n%3) return false;
        bool visited[10];
        for(int i=0;i<m;i++)
        {
            memset(visited,false,sizeof(visited));
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    int k=board[i][j]-'0';
                    if(visited[k]) return false;
                    visited[k]=true;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            memset(visited,false,sizeof(visited));
            for(int i=0;i<m;i++)
            {
                if(board[i][j]!='.')
                {
                    int k=board[i][j]-'0';
                    if(visited[k]) return false;
                    visited[k]=true;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            memset(visited,false,sizeof(visited));
            for(int j=0;j<n;j++)
            {
                int r=i/3*3 + j/3;
                int c=i%3*3 + j%3;
                if(board[r][c]!='.')
                {
                    int k=board[r][c]-'0';
                    if(visited[k]) return false;
                    visited[k]=true;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<9;i++)
        {
            bool flag[9]={false};
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!flag[board[i][j]-'1']) flag[board[i][j]-'1']=true;
                    else return false;
                }
            }
        }
        for(int j=0;j<9;j++)
        {
            bool flag[9]={false};
            for(int i=0;i<9;i++)
            {
                if(board[i][j]!='.')
                {
                    if(!flag[board[i][j]-'1']) flag[board[i][j]-'1']=true;
                    else return false;
                }
            }
        }
        for(int k=0;k<9;k++)
        {
            bool flag[9]={false};
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                {
                    int x=k/3*3+i;
                    int y=k%3*3+j;
                    if(board[x][y]!='.')
                    {
                        if(!flag[board[x][y]-'1']) flag[board[x][y]-'1']=true;
                        else return false;
                    }
                }
        }
        return true;
    }
};
