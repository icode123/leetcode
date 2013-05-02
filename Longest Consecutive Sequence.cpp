class Solution {
private:
    set<int> hash;
public:
    int getcount(set<int> &hash,int num,bool mark)
    {
        int count=0;
        while(hash.find(num)!=hash.end())
        {
            count++;
            hash.erase(hash.find(num));
            if(mark) num++;
            else num--;
        }
        return count;
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!num.size()) return 0;
        for(int i=0;i<num.size();i++)
        {
            hash.insert(num[i]);
        }
        int ret=0;
        for(int i=0;i<num.size();i++)
        {
            if(hash.find(num[i])!=hash.end())
            {
                ret=max(ret,getcount(hash,num[i],false)+getcount(hash,num[i]+1,true));
            }
        }
        return ret;
    }
};
