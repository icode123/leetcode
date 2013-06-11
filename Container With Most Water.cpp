//类似于2Sum的思想，两边设一个指针，然后计算area，如果height[i] <= height[j]，那么i++，因为在这里height[i]是瓶颈，j往里移只会减少面积，不会再增加area。
//这是一个贪心的策略，每次取两边围栏最矮的一个推进，希望获取更多的水。

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size()<2) return 0;
        int i=0,j=height.size()-1;
        int ret=0;
        while(i<j)
        {
           int area=(j-i)*min(height[i],height[j]); 
           ret=max(ret,area);
           if(height[i]<=height[j]) i++;
           else j--;
        }
        return ret;
    }
};
