class Solution {
private:
vector<vector<int> > ret;
public:
    void dfs(vector<int> &num,vector<int> path,int dep,int curSum,int target)
    {
        if(curSum>target) return;
        if(curSum==target)
        {
            ret.push_back(path);
            return;
        }
        for(int i=dep;i<num.size();i++)
        {
            if(i>dep && num[i]==num[i-1]) continue;
            curSum+=num[i];
            path.push_back(num[i]);
            dfs(num,path,i+1,curSum,target);
            curSum-=num[i];
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(num.size()==0) return ret;
        sort(num.begin(),num.end());
        vector<int> path;
        path.clear();
        dfs(num,path,0,0,target);
        return ret;
    }
};



