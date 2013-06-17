class Solution {
private:
vector<string> ret;
public:
    void dfs(string sln,int l,int r)
    {
        if(l==0 && r==0)
        {
            ret.push_back(sln);
            return;
        }
        if(l>0) dfs(sln+'(',l-1,r);
        if(r>l) dfs(sln+')',l,r-1);
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(n<=0) return ret;
        dfs("",n,n);
        return ret;
    }
};
