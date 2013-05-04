//不用考虑重复的问题

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
    vector<vector<int> > subsets(vector<int> &S) {
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

