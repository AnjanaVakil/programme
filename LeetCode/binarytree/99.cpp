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
//BST 显式中序遍历 依次递增的顺序
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        pair<int,int> swapped=findTwoSwapped(nums);
        recover(root,2,swapped.first,swapped.second);
    }
    void inorder(TreeNode* root,vector<int>& nums){
        if(root){
            inorder(root->left,nums);
            nums.push_back(root->val);
            inorder(root->right,nums);
        }
    }
    pair<int,int> findTwoSwapped(vector<int>& nums){
        int x=-1,y=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                y=nums[i+1];
                if(x==-1){
                    x=nums[i];
                }
                else break;
            }
        }
        return {x,y};
    } 
    void recover(TreeNode* root,int count,int x,int y){
        if(root){
            if(root->val==x || root->val==y){
                root->val= root->val==x ? y:x;
                if(--count==0) return;
            }
            recover(root->left,count,x,y);
            recover(root->right,count,x,y);
        }
    }
};
//隐式中序遍历（迭代中序遍历）
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x=nullptr;
        TreeNode* y=nullptr;
        TreeNode* pred=nullptr;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(pred!=nullptr && root->val<pred->val){
                y=root;
                if(x==nullptr){
                    x=pred;
                }
                else break;
            }
            pred=root;
            root=root->right;
        }
        swap(x->val,y->val);
    }
};
//Morris 遍历算法，该算法能将非递归的中序遍历空间复杂度降为 O(1)。



