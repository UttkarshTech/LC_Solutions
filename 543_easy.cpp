int maxH = 0;
int height(TreeNode *root){
    if (!root)
        return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    int h = 1 + max(hl, hr);
    maxH = max(maxH, hr + hl);
    return h;
}
int diameterOfBinaryTree(TreeNode* root) {
    //your code goes here
    height(root);
    return maxH;
}