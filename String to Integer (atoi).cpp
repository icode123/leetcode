//各种边界情况讨论

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         assert(str != NULL);        
         while(isspace(*str))
             str++;            
         int sign = *str == '-' ? -1 : 1;         
         if (*str == '-' || *str == '+')
             str++;            
         int ret = 0;
         while(isdigit(*str))
         {
             int digit = *str - '0';            
             if (INT_MAX / 10 >= ret)
                 ret *= 10;
             else
                 return sign == -1 ? INT_MIN : INT_MAX;                 
             if (INT_MAX - digit >= ret)
                 ret += digit;
             else
                 return sign == -1 ? INT_MIN : INT_MAX;                
             str++;
         }         
         return ret * sign;
    }
};
