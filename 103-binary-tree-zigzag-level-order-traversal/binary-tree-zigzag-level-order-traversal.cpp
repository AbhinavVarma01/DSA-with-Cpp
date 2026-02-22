/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool LtoR = true;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* root = q.front();
                q.pop();
                level.push_back(root->val);

                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(!LtoR) reverse(level.begin(), level.end());
            result.push_back(level);
            LtoR = !LtoR;
        }
        return result;
    }
        
};