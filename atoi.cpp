//剑指offer
class Solution {
public:
    long long StrToIntCore(const char *str,int minus,bool &status)
    {
        long long num=0;
        while(*str!='\0')
        {
            if(*str>='0' && *str<='9')
            {
                num=num*10+minus*(*str-'0');
                if((minus==1 && num>0x7fffffff)||(minus==-1 && num<(signed int)0x80000000))
                {
                    num=0;
                    break;
                }
                str++;
            }
            else
            {
                num=0;
                break;
            }
        }
        if(*str=='\0')
        {
            status=true;
        }
        return num;
    }
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool status=false;
        long long num=0;
        int minus=1;
        if(str==NULL||*str=='\0')
        {
            return 0;
        }
        while(*str!='\0'&&*str==' ') str++;
        if(*str!='\0')
        {
            if(*str=='+') str++;
            else if(*str=='-')
            {
                minus=-1;
                str++;
            }
        }
        if(*str!='\0')
        {
            num=StrToIntCore(str,minus,status);
        } 
        return (int)num;
    }
};
