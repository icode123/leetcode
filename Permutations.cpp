class Solution {
private:
vector<vector<int> > ret;
public:
    void dfs(vector<int> &num,vector<bool> &used,int dep,int maxdep,vector<int> path)
    {
        if(dep==maxdep)
        {
            ret.push_back(path);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(!used[i])
            {
                used[i]=true;
                path.push_back(num[i]);
                dfs(num,used,dep+1,maxdep,path);
                used[i]=false;
                path.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(num.size()==0) return ret;
        vector<bool> used(num.size(),false);
        vector<int> path;
        path.clear();
        dfs(num,used,0,num.size(),path);
        return ret;
    }
};
