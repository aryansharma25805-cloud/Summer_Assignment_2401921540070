
class Solution {
public:
    TreeNode* bt(vector<int> &pre, int pres, int preend, vector<int> &in, int ins, int ine, unordered_map<int,int> &m){
        if(pres>preend || ins > ine) return NULL;
        TreeNode* root = new TreeNode(pre[pres]);
        int inroot = m[root->val];
        int nl = inroot - ins;
        root->left = bt(pre, pres+1, pres+nl, in, ins, inroot-1,m);
        root->right = bt(pre, pres+nl+1, preend, in, inroot+1,ine , m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        TreeNode* root = bt(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
        return root;
    }
};
