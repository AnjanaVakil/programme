//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//注意是叶子节点。
//什么是叶子节点，左右孩子都为空的节点才是叶子节点！

//DFS
//深度优先搜索（depth-first seach，DFS）在搜索到一个新的节点时，立即对该新节点进行遍历；
//因此遍历需要用先入后出的栈来实现，也可以通过与栈等价的递归来实现
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        
        int min_depth=INT_MAX;
        if(root->left){
            min_depth=min(minDepth(root ->left),min_depth);
        }
        if(root->right){
            min_depth=min(minDepth(root->right),min_depth);
        }
        return min_depth+1;
    }
};
//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        queue<pair<TreeNode*,int>> que;
        que.emplace(root,1);

        while(!que.empty()){
            TreeNode* node=que.front().first;
            int depth=que.front().second;
            que.pop();
            if(node->left==nullptr && node->right==nullptr) return depth;
            if(node->left){
                que.emplace(node->left,depth+1);
            }
            if(node->right){
                que.emplace(node->right,depth+1);
            }
        }
        return 0;
    }
};
//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        queue<TreeNode*> que;
        que.push(root);
        int depth=1;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(node->left==nullptr && node->right==nullptr) return depth;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            depth+=1;
        }
        return depth;
    }
};
//
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        if(root->left!=nullptr && root->right==nullptr) return 1+minDepth(root->left);
        if(root->right!=nullptr && root->left==nullptr) return 1+minDepth(root->right);
        
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};
