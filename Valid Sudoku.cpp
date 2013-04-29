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
