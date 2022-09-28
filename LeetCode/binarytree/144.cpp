//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* root,vector<int>& res){
        if(root){
            res.push_back(root->val);
            preorder(root->left,res);
            preorder(root->right,res);
        }
    }
};
//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* root,vector<int>& res){
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }
            if(!stk.empty()){
                root=stk.top();
                stk.pop();
                root=root->right;
            }
        }
    }
};
//
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }
            if(!stk.empty()){
                root=stk.top();
                stk.pop();
                root=root->right;
            }
        }
        return res;
    }
};
//
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            root=root->right;
        }
        return res;
    }
};
//Morris遍历
//核心思想是利用树的大量空闲指针，实现空间开销的极限缩减
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        TreeNode *p1=root,*p2=nullptr;
        while(p1!=nullptr){
            p2=p1->left;
            if(p2!=nullptr){
                while(p2->right!=nullptr && p2->right!=p1){
                    p2=p2->right;
                }
                if(p2->right==nullptr){
                    res.emplace_back(p1->val);
                    p2->right=p1;
                    p1=p1->left;
                    continue;
                }else{
                    p2->right=nullptr;
                }
            }else{
                res.emplace_back(p1->val);
            }
            p1=p1->right;
        }
        return res;
    }
};
