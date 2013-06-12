/*
算法描述：
1、从尾部开始往前寻找两个相邻的元素
第1个元素i，第2个元素j（从前往后数的），且i<j
2、再从尾往前找第一个大于i的元素k。将i、k对调
3、[j,last)范围的元素置逆（颠倒排列）
*/

class Solution {
public:
    void reverse(vector<int> &num,int l,int r)
    {
        while(l<=r)
        {
            swap(num[l],num[r]);
            l++;
            r--;
        }
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()<=1) return;
        int i,j,k;
        for(j=num.size()-1;j>0;j--)
        {
            if(num[j-1]<num[j]) break;
        }
        if(j==0) reverse(num,0,num.size()-1);
        else
        {
            i=j-1;
            for(k=num.size()-1;k>i;k--)
            {
                if(num[i]<num[k])
                {
                    swap(num[i],num[k]);
                    break;
                }
            }
            reverse(num,j,num.size()-1);
        }
    }
};
