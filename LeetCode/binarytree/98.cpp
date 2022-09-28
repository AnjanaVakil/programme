/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    bool helper(TreeNode* root,long long lower,long long upper){
        if(root==nullptr) return true;
        if(root->val<=lower || root->val>=upper) return false;
        return helper(root->left,lower,root->val) && helper(root->right,root->val,upper);
    }
};
//中序遍历非递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder=(long long)INT_MIN-1;
        while(root || !stack.empty()){
            while(root){
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            if(root->val<=inorder) return false;
            inorder=root->val;
            root=root->right;
        }
        return true;
    }
};
class Solution {
public:
    long long pre=(long long)INT_MIN-1;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        //访问左子树
        if(!isValidBST(root->left)) return false;

        //访问结点
        if(root->val<=pre) return false;
        pre=root->val;

        //访问右子树
        return isValidBST(root->right);
    }
};