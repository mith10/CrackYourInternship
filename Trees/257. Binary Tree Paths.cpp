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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;              
        vector<string> currentPathNodes;   
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return; 
            }
            currentPathNodes.push_back(to_string(node->val));
            if (!node->left && !node->right) {
                paths.push_back(join(currentPathNodes));
            } else {
                
                dfs(node->left);
                dfs(node->right);
            }
            currentPathNodes.pop_back();
        };
      
        dfs(root);
        return paths;
    }

    string join(const vector<string>& tokens, const string& separator = "->") {
        string path;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (i > 0) {
                path += separator;
            }
            path += tokens[i];
        }
        return path; // Return the joined path as a string.
    }
};



// 257. Binary Tree Paths
// Solved
// Easy
// Topics
// Companies
// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

 

// Example 1:


// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
// Example 2:

// Input: root = [1]
// Output: ["1"]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// -100 <= Node.val <= 100