class Solution {
private:
vector<vector<int> > ret;
public:
    void dfs(vector<int> &candidates,vector<int> path,int dep,int curSum,int 

target)
    {
        if(curSum>target) return;
        if(curSum==target)
        {
            ret.push_back(path);
            return;
        }
        for(int i=dep;i<candidates.size();i++)
        {
            if(i>dep && candidates[i]==candidates[i-1]) continue;
            curSum+=candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates,path,i,curSum,target);
            curSum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(candidates.size()==0) return ret;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        path.clear();
        dfs(candidates,path,0,0,target);
        return ret;
    }
};
