class Solution {
public:
    bool check(string s)
    {
        for(int i=0;i<s.size()/2;i++)
           if(s[i]!=s[s.size()-1-i]) return false;
        return true;
    }
    void dfs(vector<vector<string>> &ret,vector<string> &rebin,string &s,int beg,int size)
    {
        if(beg==size)
        {
            ret.push_back(rebin);
            return ;
        }
        for(int i=1;i<=size-beg;i++)
        {
            if(check(s.substr(beg, i)))
            {
                rebin.push_back(s.substr(beg, i));
                dfs(ret,rebin,s,beg+i,size);
                rebin.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> ret;
        vector<string> rebin;
        dfs(ret,rebin,s,0,s.size());
        return ret;
    }
};
