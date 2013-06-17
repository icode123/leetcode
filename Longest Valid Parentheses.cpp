struct Node
{
    char ch;
    int index;
    Node(char c,int idx):ch(c),index(idx) { }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return 0;
        stack<Node> st;
        int ret=0;
        st.push(Node(')',-1));
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(Node('(',i));
            else
            {
                Node tmp=st.top();
                if(tmp.ch=='(')
                {
                    st.pop();
                    ret=max(ret,i-st.top().index);
                }
                else st.push(Node(')',i));
            }
        }
        return ret;
    }
};

