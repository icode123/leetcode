class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows<2) return s;
        int n=s.size();
        int l=2*nRows-2;
        string res;
        res.clear();
        for(int i=0;i<n;i+=l)
        {
            res.push_back(s[i]);
        }
        for(int i=1;i<nRows-1;i++)
            for(int j=i;j<n;j+=l)
            {
                res.push_back(s[j]);
                int k=j-i+l-i;
                if(k<n) res.push_back(s[k]);
            }
        for(int i=nRows-1;i<n;i+=l)
        {
            res.push_back(s[i]);
        }
        return res;
    }
};
