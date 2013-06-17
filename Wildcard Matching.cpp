class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s=='\0')
        {
            if(*p=='\0') return true;
            else if(*p=='*')
            {
                do
                {
                    p++;
                }while(*p=='*');
                return *p=='\0';
            }
            else return false;
        }
        else
        {
            if(*p=='\0') return false;
            else if(*p=='?' || *p==*s) return isMatch(s+1,p+1);
            else if(*p=='*') return isMatch(s+1,p) || isMatch(s,p+1);
            else return false;
        }
    }
};
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *str,*ptr;
        str=s,ptr=p;
        bool star=false;
        while(*str!='\0')
        {
            if(*ptr=='?') str++,ptr++;
            else if(*ptr=='*')
            {
                star=true;
                s=str,p=ptr;
                while(*p=='*') p++;
                if(*p=='\0') return true;
                str=s,ptr=p;
            }
            else
            {
                if(*str!=*ptr)
                {
                    if(!star) return false;
                    s++;
                    str=s,ptr=p;
                }
                else str++,ptr++;
            }
        }
        while(*ptr=='*') ptr++;
        return *ptr=='\0';
    }
};


















