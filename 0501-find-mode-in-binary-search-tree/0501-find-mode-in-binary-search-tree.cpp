class Solution {
    int count = 0;
    int maxCount = 0;
    int prev = 0;
    bool hasPrev = false;

    vector<int> ans;

public:
    vector<int> findMode(TreeNode* root) {
        helper(root);
        return ans;
    }

private:
    void helper(TreeNode* root) {
        if (root == nullptr) return;

        helper(root->left);

        if (hasPrev && root->val == prev) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            ans.clear();
            ans.push_back(root->val);
            maxCount = count;
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root->val;
        hasPrev = true;

        helper(root->right);
    }
};