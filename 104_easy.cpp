int maxD = 1;
void maxDep(TreeNode* root, int d){
    if (!root)
        return;
    maxD = max(maxD, d);
    maxDep(root->left, d+1);
    maxDep(root->right, d+1);
}
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    maxDep(root, 1);
    return maxD;
}