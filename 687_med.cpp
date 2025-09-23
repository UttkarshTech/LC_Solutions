int maxLen = 0;
int lUP(TreeNode *root){
    int ll, rl;
    if (!root)
        return 0;
    ll = lUP(root->left);
    rl = lUP(root->right);
    if (ll==0 && rl==0)
        return 1;
    if (ll==0){
        if (root->val == root->right->val) {
            maxLen = max(maxLen, rl);
            return rl+1;
        }
        else return 1;
    }
    else if (rl == 0){
        if (root->val == root->left->val) {
            maxLen = max(maxLen, ll);
            return ll+1;
        }
        else return 1;
    }
    else {
        if (root->val == root->left->val && root->val == root->right->val){
            maxLen = max(maxLen, ll + rl);
            return 1 + max(ll, rl);
        } else if (root->val == root->left->val) {
            maxLen = max(maxLen, ll);
            return 1 + ll;
        }
        else if (root->val == root->right->val){ 
            maxLen = max(maxLen, rl);
            return 1 + rl;
        }
        else return 1;
    }
}
int longestUnivaluePath(TreeNode* root) {
    lUP(root);
    return maxLen;
}