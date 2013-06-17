class Solution {
public:
    int div(long long int dividend,long long int divisor)
    {
        if(divisor==0 || dividend<divisor) return 0;
        if(divisor==1) return dividend;
        long long int tmp=divisor,k=0;
        for(;dividend>=tmp;k++)
        {
            tmp<<=1;
        }
        return div(dividend-(tmp>>1),divisor)+(1<<(k-1));
    }
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int d0=dividend;
        long long int d1=divisor;
        bool negative;
        if((d0>=0 && d1>=0) || (d0<=0 && d1<=0)) negative=false;
        else negative=true;
        int ret=div(abs(d0),abs(d1));
        return negative ? -ret:ret;
    }
};
