class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=1) return 0;
        int minstep=0;
        int maxlen=0;
        int i=0;
        while(i<n)
        {
            if(A[i]>0) minstep++;
            else return 0;
            maxlen=i+A[i];
            if(maxlen>=n-1) return minstep;
            int tmp=0;
            for(int j=i+1;j<=maxlen;j++)
            {
                if(tmp<=j+A[j])
                {
                    tmp=j+A[j];
                    i=j;
                }
            }
        }
        return minstep;
    }
};
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=1) return 0;
        vector<int> res(n,0);
        res[n-1]=0;
        const int noWay=n+1;
        for(int i=n-2;i>=0;i--)
        {
            int minstep=noWay;
            for(int j=i+1;j<=i+A[i]&&j<n;j++)
            {
                if(res[j]+1<minstep) minstep=res[j]+1;
            }
            res[i]=minstep;
        }
        return res[0]==noWay ? 0:res[0];
    }
};
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=1) return 0;
        vector<int> res(n,0);
        res[0]=0;
        int maxpos=0;
        for(int i=0;i<=maxpos;i++)
        {
            int pos=i+A[i];
            if(pos>=n) pos=n-1;
            if(pos>maxpos)
            {
                for(int j=maxpos+1;j<=pos;j++) res[j]=res[i]+1;
                maxpos=pos;
            }
            if(maxpos==n-1) return res[n-1];
        }
    }
};
