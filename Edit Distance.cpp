class Solution {
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int>> res(len1+1,vector<int>(len2+1));
        res[0][0]=0;
        for(int i=1;i<=len1;i++) res[i][0]=i;
        for(int i=1;i<=len2;i++) res[0][i]=i;
        for(int i=1;i<=len1;i++)
           for(int j=1;j<=len2;j++)
           {
               if(word1[i-1]==word2[j-1]) res[i][j]=res[i-1][j-1];
               else res[i][j]=min(res[i-1][j-1],min(res[i][j-1],res[i-1][j]))+1;
           }
        return res[len1][len2];
    }
};
