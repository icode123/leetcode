class Solution {
public:
    int binarySearch(int A[], int n, int target)
    {
        if(A==NULL || n<=0) return 0;
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=0) return 0;
        return binarySearch(A,n,target);
    }
};
