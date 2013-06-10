struct Node
{
    int val;
    int index;
    Node(int v,int i):val(v),index(i) { }
};
bool compare(const Node &lhs,const Node &rhs)
{
    return lhs.val<rhs.val;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Node> tmp;
        vector<int> ret;
        if(numbers.size()<=1) return ret;
        for(int i=0;i<numbers.size();i++)
        {
            tmp.push_back(Node(numbers[i],i+1));
        }
        sort(tmp.begin(),tmp.end(),compare);
        int i=0,j=tmp.size()-1;
        while(i<j)
        {
            int sum=tmp[i].val+tmp[j].val;
            if(sum==target)
            {
                int minindex=min(tmp[i].index,tmp[j].index);
                int maxindex=max(tmp[i].index,tmp[j].index);
                ret.push_back(minindex);
                ret.push_back(maxindex);
                return ret;
            }
            else if(sum>target) j--;
            else i++;
        }
    }
};
