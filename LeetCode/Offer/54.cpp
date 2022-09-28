/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//中序遍历 递增序列
class Solution {
public:
    vector<int> temp;
    int kthLargest(TreeNode* root, int k) {
        inorder(root);
        return temp[temp.size()-k];
    }
    void inorder(TreeNode* root){
        //递归超出时间限制
        // while(root){
        //     inorder(root->left);
        //     temp.push_back(root->val);
        //     inorder(root->right);
        // }
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            temp.push_back(root->val);
            root=root->right;
        }
    }
};
//中序遍历倒序 为 递减序列 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res;
    int kthLargest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
    void inorder(TreeNode* root,int k){
        //递归超出时间限制
        // while(root){
        //     inorder(root->left);
        //     temp.push_back(root->val);
        //     inorder(root->right);
        // }
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root=root->right;
            }
            root=stk.top();
            stk.pop();
            if(k==0) return;
            if(--k ==0) res=root->val;
            root=root->left;
        }
    }
};

