class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hayLen=strlen(haystack);
        int needLen=strlen(needle);
        if(needLen>hayLen) return NULL;
        for(int i=0;i<=hayLen-needLen;i++)
        {
            char *p=haystack+i;
            char *q=needle;
            while(*q!='\0')
            {
                if(*p!=*q) break;
                p++;
                q++;
            }
            if(*q=='\0') return haystack+i;
        }
        return NULL;
    }
};



