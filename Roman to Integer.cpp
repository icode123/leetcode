/*
知道罗马数字的定义之后是很简单的，比int to roman简单。
 从前往后扫描，用一个临时变量记录分段数字。
如果当前处理的字符对应的值和上一个字符一样，那么临时变量加上这个字符。比如III = 3
如果当前比前一个大，说明这一段的值应该是当前这个值减去前面记录下的临时变量中的值。比如IIV = 5 – 2
如果当前比前一个小，那么就可以先将临时变量的值加到结果中，然后开始下一段记录。比如VI = 5 + 1
*/

class Solution {
public:
    int map(char c)
    {
        switch(c)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pre=1001;
        int ret=0;
        int cur;
        for(int i=0;i<s.size();i++)
        {
            cur=map(s[i]);
            ret+=cur;
            if(cur>pre) ret-=2*pre;
            pre=cur;
        }
        return ret;
    }
};
