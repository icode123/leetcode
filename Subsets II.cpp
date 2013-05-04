//方法一：用一个数组来记录某个数字是否被使用过，如果前面的数字和本数相同，则前面的数必须被使用过本数才能被使用；
class Solution {
private:
    vector<vector<int> > ret;
public:
    void dfs(int dep,int maxdep,vector<int> &num,vector<int> a,int start)
    {
        ret.push_back(a);
        if(dep==maxdep) return;
        for(int i=start;i<num.size();i++)
        {
            if(i!=start && num[i]==num[i-1]) continue;
            vector<int> b(a);
            b.push_back(num[i]);
            dfs(dep+1,maxdep,num,b,i+1);
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!S.size()) return ret;
        sort(S.begin(),S.end());
        vector<int> a;
        dfs(0,S.size(),S,a,0);
        return ret;
    }
};

//方法二：用STL的set去重或者vector的unique方法去重；
//vector的unique方法
class Solution {
private:
    vector<vector<int> > ret;
public:
    void dfs(int dep,int maxdep,vector<int> &num,vector<int> a,int start)
    {
        ret.push_back(a);
        if(dep==maxdep) return;
        for(int i=start;i<num.size();i++)
        {
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep+1,maxdep,num,b,i+1);
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!S.size()) return ret;
        sort(S.begin(),S.end());
        vector<int> a;
        dfs(0,S.size(),S,a,0);
        sort(ret.begin(),ret.end());
        ret.resize(unique(ret.begin(),ret.end())-ret.begin());
        return ret;
    }
};
//STL的set
class Solution {
private:
    vector<vector<int> > ret;
public:
    void dfs(int dep,int maxdep,set<vector<int>> &sret,vector<int> &num,vector<int> a,int start)
    {
        if(sret.find(a)==sret.end())
        {
            sret.insert(a);
            ret.push_back(a);
        }
        if(dep==maxdep) return;
        for(int i=start;i<num.size();i++)
        {
                vector<int> b(a);
                b.push_back(num[i]);
                dfs(dep+1,maxdep,sret,num,b,i+1);
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(!S.size()) return ret;
        sort(S.begin(),S.end());
        vector<int> a;
        set<vector<int>> sret;
        dfs(0,S.size(),sret,S,a,0);
        return ret;
    }
};

