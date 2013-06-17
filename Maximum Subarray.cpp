class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=0) return 0;
        int nStart=A[n-1];
        int nAll=A[n-1];
        for(int i=n-2;i>=0;i--)
        {
            nStart=max(A[i],A[i]+nStart);
            nAll=max(nAll,nStart);
        }
        return nAll;
    }
};
