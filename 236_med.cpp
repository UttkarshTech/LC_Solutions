TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** res) {
    if (!root) return NULL;
    TreeNode* lc = lca(root->left, p, q, res);
    TreeNode* rc = lca(root->right, p, q, res);
    if (root == p) {
        if (lc == q || rc == q)
            *res = root;
        else
            return p;
    } else if (root == q) {
        if (lc == p || rc == p) *res = root;
        else return q;
    } else if ((lc == p && rc == q) || (lc == q && rc == p))
        *res = root;
    else if (!lc)
        return rc;
    return lc;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // your code goes here
    if (p == q)
        return p;
    TreeNode* res = NULL;
    lca(root, p, q, &res);
    return res;
}