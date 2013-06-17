class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        map<string,vector<string>> hashmap;
        ret.clear();
        hashmap.clear();
        if(strs.size()<2) return ret;
        for(int i=0;i<strs.size();i++)
        {
            string sortStr(strs[i]);
            sort(sortStr.begin(),sortStr.end());
            hashmap[sortStr].push_back(strs[i]);
        }
        map<string,vector<string>>::iterator it=hashmap.begin();
        for(;it!=hashmap.end();it++)
        {
            if((it->second).size()>1)
            {
                for(int i=0;i<(it->second).size();i++) ret.push_back((it->second)[i]);
            }
        }
        return ret;
    }
};
