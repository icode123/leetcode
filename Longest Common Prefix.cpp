/*
挨个比较
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;
        if(strs.size()==0) return ret;
        if(strs.size()==1) return strs[0];
        int index=0;
        while(true)
        {
            int i=0;
            char ch=strs[i][index];
            if(ch!='\0')
            {
                for(i++;i<strs.size();i++)
                {
                    if(strs[i][index]!=ch) return ret;
                }
                ret+=ch;
                index++;
            }
            else return ret;
        }
        return ret;
    }
};
