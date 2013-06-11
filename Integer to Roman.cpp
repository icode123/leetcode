//

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
