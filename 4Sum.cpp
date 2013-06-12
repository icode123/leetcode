/*
O(n3)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        if(num.size()<4) return ret;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-3;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j=i+1;j<num.size()-2;j++)
            {
                if(j>i+1 && num[j]==num[j-1]) continue;
                int start=j+1;
                int end=num.size()-1;
                while(start<end)
                {
                    if(start>j+1 && num[start]==num[start-1])
                    {
                        start++;
                        continue;
                    }
                    if(end<num.size()-1 && num[end]==num[end+1])
                    {
                        end--;
                        continue;
                    }
                    int sum=num[i]+num[j]+num[start]+num[end];
                    if(sum==target)
                    {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[start]);
                        tmp.push_back(num[end]);
                        ret.push_back(tmp);
                        start++;
                    }
                    else if(sum<target) start++;
                    else end--;
                }
            }
        }
        return ret;
    }
};
