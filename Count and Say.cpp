class Solution {
 public:
     string countAndSay(int n) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         string s = "1";
         for(int i = 2; i <= n; i++)
         {
             string nextS;
             char key = '-';
             int j = 0;
             int count = 0;
             while(j < s.size())
             {
                 if (key == s[j])
                     count++;
                 else
                 {
                     if (key != '-')
                     {
                         nextS = nextS + (char)(count + '0');
                         nextS = nextS + key;
                     }
                     key = s[j];
                     count = 1;                    
                 }
                 j++;
             }
             nextS = nextS + (char)(count + '0');
             nextS = nextS + key; 
             s = nextS;
         } 
         return s;
     }
 };

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return "";
        string ret("1");
        for(int i=2;i<=n;i++)
        {
            string tmp;
            int count=1;
            char ch=ret[0];
            for(int j=1;j<ret.size();j++)
            {
                if(ret[j]==ch) count++;
                else
                {
                    tmp+=(char)count+'0';
                    tmp+=ch;
                    ch=ret[j];
                    count=1;
                }
            }
            tmp+=(char)count+'0';
            tmp+=ch;
            ret=tmp;
        }
        return ret;
    }
};
