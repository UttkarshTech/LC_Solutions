bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;
    if ((!p && q) || (p && !q))
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);

}
bool isSymmetric(TreeNode* root) {
    //your code goes here
    return isSameTree(root->left, root->right);
}