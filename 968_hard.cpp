int camCount = 0;
int placeCam(TreeNode* root){
    if (!root)
        return 0;
    int leftNeed = placeCam(root->left);
    int rightNeed = placeCam(root->right);
    if (leftNeed == 1 || rightNeed == 1){
        camCount++;
        return -1;
    } else if (leftNeed == 0 && rightNeed == 0) return 1;
    else return 0;
}
int minCameraCover(TreeNode* root) {
    if (!root->left && !root->right)
        return 1;
    int x = placeCam(root);
    return x==1 ? ++camCount : camCount;
}