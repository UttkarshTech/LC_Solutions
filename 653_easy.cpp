vector<int> inorder;
void inordTrav(TreeNode *root){
    if (!root)
        return;
    inordTrav(root->left);
    inorder.push_back(root->val);
    inordTrav(root->right);
}
bool findTarget(TreeNode* root, int k){
    //your code goes here
    inordTrav(root);
    int i = 0, j = inorder.size()-1;
    while (i<j){
        int sum = inorder[i] + inorder[j];
        if (sum == k)
            return true;
        else if (sum < k)
            i++;
        else j--;
    }
    return false;
}