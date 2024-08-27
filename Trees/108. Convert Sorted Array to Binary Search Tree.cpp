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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;  
        return solve(nums, l, h);
    }

    TreeNode* solve(vector<int>& nums, int l, int h) {
        if (l > h) {
            return nullptr;
        }

        int m = (l + h) / 2;

        TreeNode* node = new TreeNode(nums[m]);
        node->left = solve(nums, l, m - 1);
        node->right = solve(nums, m + 1, h);
        return node;
    }
};
// 108. Convert Sorted Array to Binary Search Tree
// Solved
// Easy
// Topics
// Companies
// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:


// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in a strictly increasing order.