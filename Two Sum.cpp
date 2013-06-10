//o(nlogn)
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
//o(n)
 int len = numbers.size();  
        assert(len >= 2);             
          
        vector<int> ret(2, 0);  
          
        map<int, int> mapping;              // default all are 0  
        vector<long long> mul(len, 0);  
          
        for(int i = 0; i < len; i++){  
            mul[i] = (target - numbers[i]) * numbers[i];  
              
            if(mapping[mul[i]] > 0){        // not default 0  
                if(numbers[i] + numbers[mapping[mul[i]] - 1] == target){  
                    ret[0] = mapping[mul[i]];  
                    ret[1] = i + 1;  
                    break;  
                }  
                  
            } else {  
                mapping[mul[i]] = i + 1;    // larger than 0  
            }  
        }  
          
        return ret; 
