/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //2016-11-04 Review
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){
            TreeNode* node = new TreeNode(nums[0]);
            if(nums.size() == 2){
                TreeNode* root = new TreeNode(nums[1]);
                root->left = node;
                return root;
            }
            return node;
        }
        return construct(nums,0, nums.size()-1);
    }
    
    TreeNode* construct(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(nums,start, mid-1);
        root->right = construct(nums,mid+1, end);
        return root;
    }
};
