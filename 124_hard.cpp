int maxS = INT_MIN;
int pathSum(TreeNode *root){
    if (!root)
        return 0;
    int sl = pathSum(root->left);
    int sr = pathSum(root->right);
    sl = sl <= 0 ? 0 : sl;
    sr = sr <= 0 ? 0 : sr;
    int s = root->val + max(sl, sr);
    maxS = max(maxS, root->val + sl + sr);
    return s;
}
int maxPathSum(TreeNode* root) {
    //your code goes here
    pathSum(root);
    return maxS;
}