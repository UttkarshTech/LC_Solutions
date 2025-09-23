void trav(TreeNode *root, int lvl, int col, map<int, multiset<pair<int, int>>> *m){
    if (!root)
        return;
    (*m)[col].insert(make_pair(lvl, root->val)); 
    trav(root->left, lvl+1, col-1, m);
    trav(root->right, lvl+1, col+1, m);
}
vector<vector<int> > verticalTraversal(TreeNode* root) {
    map<int, multiset<pair<int, int>>> m;
    vector<vector<int>> res;
    trav(root, 0, 0, &m);
    for (auto &[key, val] : m){
        vector<int> temp;
        for (auto &p : val){
            temp.push_back(p.second);
        }
        res.push_back(temp);
    }
    return res;
}