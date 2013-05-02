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
