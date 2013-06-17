class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=1) return true;
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            if(i<=maxlen)
            {
                maxlen=maxlen>i+A[i] ? maxlen:i+A[i];
            }
        }
        return maxlen>=n-1;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=1) return true;
        int cur=n-1;
        for(int i=cur-1;i>=0;i--)
        {
            if(A[i]>=cur-i) cur=i;
        }
        return cur==0;
    }
};
