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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n == 0) {
            return ans;;
        }
        
        ans = generate_trees(1, n);
        return ans;
    }
    vector<TreeNode*> generate_trees(int start, int end) {
        vector<TreeNode*> all_trees;
        if(start> end) {
            all_trees.push_back(NULL);
            return all_trees;
        }
        
        for(int i = start; i<=end; i++) {
            vector<TreeNode*> left_trees = generate_trees(start, i-1) ;
            vector<TreeNode*> right_trees = generate_trees(i+1, end);
            for(int j =0; j<left_trees.size() ; j++) {
                for(int k = 0; k<right_trees.size() ; k++) {
                    TreeNode* ct = new TreeNode(i);
                    ct->left = left_trees[j];
                    ct->right = right_trees[k];
                    all_trees.push_back(ct);
                }
            }
        }
        return all_trees;
    }
};
