//反转溢出越界问题

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x==0) return x;
        long long result=0,multi=1;//long long
        vector<int> digits;
        int tmp=0,flag=0;
        if(x>0) flag=1;
        else
        {
            flag=-1;
            x=-x;
        }
        while(x!=0)
        {
            tmp=x%10;
            x=x/10;
            digits.push_back(tmp);
        }
        while(digits.size()!=0)
        {
            result+=digits.back()*multi;
            multi*=10;
            digits.pop_back();
        }
        result*=flag;
        if(result>=INT_MAX) return INT_MAX;
        if(result<=INT_MIN) return INT_MIN;
        return result;
    }
};
