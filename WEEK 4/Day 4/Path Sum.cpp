
class Solution {
public:
    bool helper(TreeNode* root, int target){
        if(!root) return false;
        target -= root->val;
        if(!root->left && !root->right) return target == 0;
        return (helper(root->left, target)||helper(root->right,target));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};
