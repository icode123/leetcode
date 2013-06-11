/*
罗马数字是由字符I,V,X,L,C,D,M等等表示的，其中
 I = 1;
 V = 5;
 X = 10;
 L = 50;
 C = 100;
 D = 500;
 M = 1000;
 接下来应该是V开始的重复，但是上面要加一个横线，表示对应数字的1000倍。
 而且对于某位上（以个位为例），1 – 9，应该是：I,II,III,IV,V,VI,VII,VIII,IX
 而，对于百位上，100 – 900，应该是：C,CC,CCC,CD,D,DC,DCC,DCCC,CM
 依此类推。
 */

class Solution {
public:
    string roman(int num,char ten,char five,char one)
    {
        string tmp;
        if(num==9)
        {
            tmp+=one;
            tmp+=ten;
        }
        else if(num>=5)
        {
            tmp+=five;
            while(num-->5) tmp+=one;
        }
        else if(num==4)
        {
            tmp+=one;
            tmp+=five;
        }
        else
        {
            while(num-->0) tmp+=one;
        }
        return tmp;
    }
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret;
        ret+=roman(num/1000%10,0,0,'M');
        ret+=roman(num/100%10,'M','D','C');
        ret+=roman(num/10%10,'C','L','X');
        ret+=roman(num%10,'X','V','I');
        return ret;
    }
};
