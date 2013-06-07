class Solution {
private:
vector<string> ret;
int pos[4];
public:
    bool check(string &s,int beg,int end)
    {
        string ip(s,beg,end-beg+1);
        if(ip.size()==1) return ip>="0"&& ip<="9";
        else if(ip.size()==2) return ip>="10" && ip<="99";
        else if(ip.size()==3) return ip>="100" && ip<="255";
        else return false;
    }
    void dfs(int dep,int maxdep,string &s,int start)
    {
        if(dep==maxdep)
        {
            if(start==s.size())
            {
                int beg=0;
                string ans;
                for(int i=0;i<maxdep;i++)
                {
                    string ip(s,beg,pos[i]-beg+1);
                    ans+=i==0?ip:"."+ip;
                    beg=pos[i]+1;
                }
                ret.push_back(ans);
            }
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(check(s,start,i))
            {
                pos[dep]=i;
                dfs(dep+1,maxdep,s,i+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        dfs(0,4,s,0);
        return ret;
    }
};
