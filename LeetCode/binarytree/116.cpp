/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//递归
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        connectTwoNode(root->left,root->right);
        return root;
    }
    void connectTwoNode(Node* node1,Node* node2){
        if(node1==nullptr || node2==nullptr) return;

        node1->next=node2;

        connectTwoNode(node1->left,node1->right);
        connectTwoNode(node2->left,node2->right);
        connectTwoNode(node1->right,node2->left);
    }
};
//层序遍历 -->超出时间限制
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();

                if(i<size-1){
                    node->next=q.front();
                }

                if(node->left!=nullptr) q.push(root->left);
                if(node->right!=nullptr) q.push(root->right);
            }
        }
        return root;
    }
};
//递归
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        connection(root);
        return root;
    }
    void connection(Node* root){
        if(root->left==nullptr) return;

        root->left->next=root->right; 
        
        if(root->next!=nullptr){
            root->right->next=root->next->left;
        }
        
        connect(root->left);
        connect(root->right);
    }
};