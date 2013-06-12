/*
避免出现重复解的方法：先排序，后比较
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        if(num.size()<3) return ret;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;//避免出现重复解
            int start=i+1;
            int end=num.size()-1;
            while(start<end)
            {
                if(start>i+1 && num[start]==num[start-1])
                {
                    start++;
                    continue;
                }
                if(end<num.size()-1 && num[end]==num[end+1])
                {
                    end--;
                    continue;
                }
                int sum=num[i]+num[start]+num[end];
                if(sum==0)
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[start]);
                    tmp.push_back(num[end]);
                    ret.push_back(tmp);
                    start++;
                }
                else if(sum<0) start++;
                else end--;
            }
        }
        return ret;
    }
};
