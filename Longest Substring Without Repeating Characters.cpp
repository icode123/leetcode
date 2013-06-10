class Solution {
private:
bool used[256];
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return 0;
        memset(used,false,sizeof(used));
        int maxlen=0;
        int i=0,j=0;
        while(j<s.size())
        {
            if(used[s[j]]==false)
            {
               used[s[j]]=true;
               j++;
            }
            else
            {
                maxlen=max(maxlen,j-i);
                while(s[i]!=s[j])
                {
                    used[s[i]]=false;
                    i++;
                }
                i++;
                j++;
            }
        }
        return max(maxlen,j-i);//zhuyi
    }
};
