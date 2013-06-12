/*
类似于3Sum,边求解边记录ABS()
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()<3) return 0;
        sort(num.begin(),num.end());
        int minsum=num[0]+num[1]+num[2];
        int mindiff=abs(target-minsum);
        for(int i=0;i<num.size()-2;i++)
        {
            int left=i+1;//重复情况还需优化一下，参考3Sum.cpp
            int right=num.size()-1;
            while(left<right)
            {
                int sum=num[i]+num[left]+num[right];
                if(abs(target-sum)<mindiff)
                {
                    minsum=sum;
                    mindiff=abs(target-sum);
                }
                if(sum==target) return minsum;
                else if(sum>target) right--;
                else left++;
            }
        }
        return minsum;
    }
};
