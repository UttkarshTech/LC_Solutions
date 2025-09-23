bool pathSum(TreeNode* root, int targetSum, int curSum){
    if (!root)
        return false;
    if (!root->left && !root->right && (curSum + root->val == targetSum))
        return true;
    return pathSum(root->left, targetSum, curSum+root->val) || pathSum(root->right, targetSum, curSum+root->val);

}
bool hasPathSum(TreeNode* root, int targetSum) {
    return pathSum(root, targetSum, 0);
}