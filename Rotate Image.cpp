class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size()==0 || matrix[0].size()==0) return;
        for(int i=0;i<matrix.size()-1;i++)
           for(int j=0;j<matrix[0].size()-1-i;j++)
           {
               swap(matrix[i][j],matrix[matrix.size()-1-j][matrix.size()-1-i]);
           }
        for(int i=0;i<matrix.size()/2;i++)
           for(int j=0;j<matrix[0].size();j++)
           {
               swap(matrix[i][j],matrix[matrix.size()-1-i][j]);
           }
    }
};
