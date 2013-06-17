class Solution {
private:
int ret;
int a[100];
bool canUse[100];
public:
    bool check(int y,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(abs(i-n)==abs(y-a[i])) return false;
        }
        return true;
    }
    void dfs(int dep,int maxdep)
    {
        if(dep==maxdep)
        {
            ret++;
            return;
        }
        for(int i=0;i<maxdep;i++)
        {
            if(canUse[i] && check(i,dep))
            {
                canUse[i]=false;
                a[dep]=i;
                dfs(dep+1,maxdep);
                canUse[i]=true;
            }
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret=0;
        if(n<=0) return ret;
        memset(canUse,true,sizeof(canUse));
        dfs(0,n);
        return ret;
    }
};
