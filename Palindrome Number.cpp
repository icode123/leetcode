//

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         if (x<0)
             return false;
         if (x==0)
             return true;    
         int base=1;
         int xx=x;//注意
         while(xx/10!=0)
         {
             base*=10;
             xx/=10;//此操作会改变给定数值
         }    
         while(x)
         {
             int leftDigit=x/base;
             int rightDigit=x%10;
             if (leftDigit!=rightDigit)
                 return false;
             x=x%base/10;
             base/=100;
         }
         return true;
    }
};
