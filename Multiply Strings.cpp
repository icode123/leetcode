class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1[0]=='0' || num2[0]=='0') return "0";
        string ret(num1.size()+num2.size(),'0');
        vector<int> r(num1.size()+num2.size(),0);
        for(int i=0;i<num1.size();i++)
           for(int j=0;j<num2.size();j++)
           {
               r[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
           }
        for(int i=num1.size()+num2.size()-1;i>0;i--)
        {
            if(r[i]>9)
            {
                r[i-1]+=r[i]/10;  
            }
            ret[i]+=r[i]%10;
        }
        ret[0]+=r[0];
        return ret[0]=='0' ? string(ret.begin()+1,ret.end()):ret;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1[0]=='0' || num2[0]=='0') return "0";
        string ret(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--)
        {
            int flag=0;
            for(int j=num2.size()-1;j>=0;j--)
            {
                int digit=ret[i+j+1]-'0';
                int num=(num1[i]-'0')*(num2[j]-'0');
                int res=digit+num+flag;
                ret[i+j+1]=res%10+'0';
                flag=res/10;
            }
            int index=i-1;
            if(flag)
            {
                int digit=ret[index+1]-'0';
                int res=digit+flag;
                ret[index+1]=res%10+'0';
                flag=res/10;
            }
        }
        return ret[0]=='0' ? string(ret.begin()+1,ret.end()):ret;
    }
};
