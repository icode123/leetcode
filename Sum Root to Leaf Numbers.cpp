/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//方法一
class Solution {
public:
  void dfs(TreeNode *root,int &sum,int cur)
	{
		if (!root)
		{
			return ;
		}
		if (!root->left && !root->right)
		{
			ret+=cur*10+root->val;
		}
		else
		{
			if (root->left)
			{
				dfs(root->left,sum,cur*10+root->val);
			}
			if (root->right)
			{
				dfs(root->right,sum,cur*10+root->val);
			}
		}
	}
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (!root)
		{
			return 0;
		}
		int sum=0;
		dfs(root,sum,0);
		return sum;
	}
};
//方法二
class Solution {
public:
    int dfs(TreeNode *root,int sum)
  {
		if (!root)
		{
			return 0;
		}
		sum=sum*10+root->val;
		if (!root->left && !root->right)
		{
			return sum;
		}
		else
		{
			return dfs(root->left,sum)+dfs(root->right,sum);
		}
	}
	int sumNumbers(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (!root)
		{
			return 0;
		}
		int sum=0;
		return dfs(root,sum);
	}
};
