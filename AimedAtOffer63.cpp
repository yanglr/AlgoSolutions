#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
{
		TreeNode *p=pRoot;
		if(p==NULL || k==0) return NULL;
		stack<TreeNode *> st;
		unsigned int count=0;
		
	while(!st.empty() || p != NULL)
	{			
		if(p != NULL)
		{
			st.push(p);
			p=p->left;
		}			
		if(p == NULL)
		{
			p=st.top();  // 取当前节点
			count++;
			if(count==k) return p;  
			st.pop();
			p=p->right;
		} 
	}
}  
};

//       6
//     /  \
//    3    8
//  /  \   / \
// 2   5  7   9

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(8);	
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	TreeNode* p=sol.KthNode(root, 3);
	printf("The value of Kth Node is: %d\n", p->val);	
	return 0;
}
