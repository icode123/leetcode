class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(A==NULL || n<=0) return vector<int>(2,-1);
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[mid]==target)
            {
                int l=0,r=0;
                while(A[mid]==A[mid-l] && mid-l>=0) l++;
                while(A[mid]==A[mid+r] && mid+r<n) r++;
                ret.push_back(mid-l+1);
                ret.push_back(mid+r-1);
                return ret;
            }
            else if(A[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return vector<int>(2,-1);
    }
};

class Solution {
public:
    int binarySearchFirst(int A[], int n, int target)
    {
        if(A==NULL || n<=0) return -1;
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[mid]==target)
            {
                if((mid>0 && A[mid-1]!=target)||mid==0) return mid;
                else right=mid-1;
            }
            else if(A[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    int binarySearchLast(int A[], int n, int target)
    {
        if(A==NULL || n<=0) return -1;
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(A[mid]==target)
            {
                if((mid<n-1 && A[mid+1]!=target)||mid==n-1) return mid;
                else left=mid+1;
            }
            else if(A[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A==NULL || n<=0) return vector<int>(2,-1);
        vector<int> ret;
        int start=binarySearchFirst(A,n,target);
        if(start==-1) return vector<int>(2,-1);
        int end=binarySearchLast(A,n,target);
        ret.push_back(start);
        ret.push_back(end);
        return ret;
    }
};
