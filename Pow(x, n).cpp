class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ret;
        if(n==0) return 1.0;
        int m=n>0 ? n:-n;
        double tmp=pow(x,m/2);
        ret=tmp*tmp;
        if(m&1) ret*=x;
        return n<0 ? 1/ret:ret;
    }
};

