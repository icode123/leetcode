//o(n2) DP
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(!n) return "";
        int maxi=0;
        int maxl=1;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                maxl=2;
                maxi=i;
            }
        for(int l=3;l<=n;l++)
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    maxl=l;
                    maxi=i;
                }
            }
        return s.substr(maxi,maxl);
    }
};

//
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret("");
        if(s.size()==0) return ret;
        vector<vector<bool>> table(s.size(),vector<bool>(s.size(),false));
        int maxlength=1;
        int maxindex=0;
		for(int i=0;i<s.size();i++)
		{
			table[i][i]=true;
		}
		for(int l=2;l<=s.size();l++)
			for(int i=0;i+l-1<s.size();i++)
			{
				int j=i+l-1;
				if(s[i]==s[j])
				{
                    if(i+1==j)
                    {
                        table[i][j]=true;
                        maxlength=2;
                        maxindex=i;
                    }
                    else if(table[i+1][j-1])
                    {
                        table[i][j]=true;
                        if(l>maxlength)
                        {
                            maxlength=l;
                            maxindex=i;
                        }
                    }
				}
			}
			return ret+s.substr(maxindex,maxlength);
    }
};

//O(N),Manacher算法
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return "";
        string trans("&#");
        for(int i=0;i<s.size();i++)
        {
            trans+=s[i];
            trans+='#';
        }
        int *p=new int[trans.size()];
        p[0]=0;
        int i,mx=0,id;  
        for(i=1;i<trans.size();i++)  
        {  
           if(mx>i)  
              p[i]=min(p[2*id-i],mx-i);  
           else  
              p[i]=1;  
           for(;trans[i+p[i]]==trans[i-p[i]];p[i]++);  
           if(p[i]+i>mx)  
           {  
              mx=p[i]+i;  
              id=i;  
           }  
        } 
        int max_len=0;
        int max_index=0;
	 
	    for(i=1;i<trans.size();i++)
	    {
	      if(p[i]>max_len)
	      {
	        max_len=p[i];
	        max_index=i;
	      }
	    }
        max_len--;
        int start=max_index-max_len;
        int end=max_index+max_len;
        string ret;
        for(int j=start;j<=end;j++)
        {
            if(trans[j]!='#') ret+=trans[j];
        }
        return ret;
    }
};
