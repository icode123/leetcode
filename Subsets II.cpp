//方法一：用一个数组来记录某个数字是否被使用过，如果前面的数字和本数相同，则前面的数必须被使用过本数才能被使用；
class Solution {
private:
    vector<vector<int> > ret;
    bool canuse[100];
public:
    void dfs(int dep,int maxdep,vector<int> &num,vector<int> a,int start)
    {
        ret.push_back(a);
        if(dep==maxdep) return;
        for(int i=start;i<num.size();i++)
        {
            if(i==0)
            {
                canuse[i]=false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep+1,maxdep,num,b,i+1);
                canuse[i]=true;
            }
            else
            {
                if(num[i]==num[i-1] && canuse[i-1]) continue;
                canuse[i]=false;
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep+1,maxdep,num,b,i+1);
                canuse[i]=true;
            }
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!S.size()) return ret;
        sort(S.begin(),S.end());
        memset(canuse,true,sizeof(canuse));
        vector<int> a;
        dfs(0,S.size(),S,a,0);
        return ret;
    }
};

//方法二：用STL去重；
