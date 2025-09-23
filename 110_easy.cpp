int height(TreeNode *root){
    if (!root)
        return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    if (hr == -1 || hl == -1)
        return -1;
    if (abs(hr-hl) >= 2)
        return -1;
    return 1 + max(hl, hr);
}
bool isBalanced(TreeNode *root){
    //your code goes here
    if (height(root) == -1) return false;
    return true;
}