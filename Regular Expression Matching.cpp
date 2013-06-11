//对于’*'的理解开始错误了，这里是指’*'号前一个字符可以出现0个或多个，而且*前面的字符有可能是’.’
//对于patten分情况讨论就可以把代码写出来了。
//而且当出现’*'的时候，需要递归去查看这个’*'，match 0个字符,1个字符,2个字符,….，等等情况。

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if('\0'==*p) return '\0'==*s;
        if(*(p+1)!='*')
        {
            if(*s==*p||(*p=='.'&&*s!='\0')) return isMatch(s+1,p+1);
            return false;
        }
        else
        {
            while(*s==*p||(*p=='.'&&*s!='\0'))
            {
                if(isMatch(s,p+2)) return true;
                s++;
            }
            return isMatch(s,p+2);
        }
    }
};
