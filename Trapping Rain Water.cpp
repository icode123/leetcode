class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=2) return 0;
        vector<int> left(n);
        int maxheight=0;
        for(int i=0;i<n;i++)
        {
            left[i]=maxheight;
            maxheight=max(maxheight,A[i]);
        }
        int water=0;
        maxheight=0;
        for(int i=n-1;i>=0;i--)
        {
            int height=min(maxheight,left[i])-A[i];
            if(height>0) water+=height;
            maxheight=max(maxheight,A[i]);
        }
        return water;
    }
};




