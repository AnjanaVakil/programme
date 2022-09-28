//后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            //左 右 根
            //根 右 左
            while(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->right;
            }
            root=stk.top();
            stk.pop();
            root=root->left;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* prev=nullptr;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(root->right==nullptr || root->right==prev){
                res.push_back(root->val);
                prev=root;
                root=nullptr;
            }else{
                stk.push(root);
                root=root->right;
            }
        }
        return res;
    }
};