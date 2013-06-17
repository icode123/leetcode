class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return true;
        stack<int> s0,s1,s2;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(') s0.push(i);
            else if(ch=='[') s1.push(i);
            else if(ch=='{') s2.push(i);
            else if(ch==')')
            {
                if(s0.size()==0) return false;
                int last=s0.top();
                if(!s1.empty() && s1.top()>last) return false;
                if(!s2.empty() && s2.top()>last) return false;
                s0.pop();
            }
            else if(ch==']')
            {
                if(s1.size()==0) return false;
                int last=s1.top();
                if(!s0.empty() && s0.top()>last) return false;
                if(!s2.empty() && s2.top()>last) return false;
                s1.pop();
            }
            else if(ch=='}')
            {
                if(s2.size()==0) return false;
                int last=s2.top();
                if(!s0.empty() && s0.top()>last) return false;
                if(!s1.empty() && s1.top()>last) return false;
                s2.pop();
            }
        }
        return s0.empty()&&s1.empty()&&s2.empty() ;
    }
};

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return true;
        stack<char> lefts;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='('||ch=='['||ch=='{') lefts.push(ch);
            else
            {
                if(lefts.size()==0) return false;
                char top=lefts.top();
                if(ch==')')
                {
                    if(top!='(') return false;
                }
                else if(ch==']')
                {
                    if(top!='[') return false; 
                }
                else if(ch=='}')
                {
                    if(top!='{') return false; 
                }
                lefts.pop();
            }
        }
        return lefts.empty();
    }
};




