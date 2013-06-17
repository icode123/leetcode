class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=0) return 0;
        int i=-1;
        int j;
        for(j=0;j<n;j++)
        {
            if(A[j]!=elem) A[++i]=A[j];
        }
        return i+1;
    }
};
