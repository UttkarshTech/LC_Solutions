vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    //your code goes here
    vector<vector<int>> res;
    if (!root)
        return res;
    deque <vector<TreeNode*>>dq;
    bool flag = true;
    dq.push_back({root});
    while (!dq.empty()){
        for (auto i : dq){
            vector<TreeNode *> temp;
            vector<int> temp2;
            for (auto j : i){
                if (j->left) temp.push_back(j->left);
                if (j->right) temp.push_back(j->right);
                temp2.push_back(j->val);
            }
            dq.pop_front();
            if (!flag) reverse(temp2.begin(), temp2.end());
            flag = !flag;
            if (temp.size()) dq.push_back(temp);
            if (temp2.size()) res.push_back(temp2);
        }
    }
    return res;
}