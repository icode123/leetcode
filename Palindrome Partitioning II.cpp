class Solution {
public:
    int minCut(string s) {
  	// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int num=s.size();
		vector<int> ret(num+1);
		for (int i=0;i<ret.size();i++)
		{
			ret[i]=i-1;
		}
		vector<vector<bool>> save(num, vector<bool>(num, false));
		for(int i=0;i<num;i++)
			for (int j=0;j<=i;j++)
			{
				if (s[j]==s[i] && (i-j<2 || save[j+1][i-1]))
				{
					save[j][i]=true;
					ret[i+1]=min(ret[i+1],ret[j]+1);
				}
			}
		return ret[num];
	}
};

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num=s.size();
        vector<vector<int>> cut(num,vector<int>(num,INT_MAX));
        vector<vector<bool>> p(num,vector<bool>(num,false));
        for(int i=0;i<num;i++)
        {
            p[i][i]=true;
            cut[i][i]=0;
        }
        for(int l=2;l<=num;l++)
           for(int i=0;i+l-1<num;i++)
           {
               int j=i+l-1;
               if(s[i]==s[j] && (i+1==j || p[i+1][j-1]))
               {
                   p[i][j]=true;
                   cut[i][j]=0;
               }
               else
               {
                   for(int k=i;k<j;k++)
                   {
                       cut[i][j]=min(cut[i][j],cut[i][k]+cut[k+1][j]+1);
                   }
               }
           }
        return cut[0][num-1];
    }
};
