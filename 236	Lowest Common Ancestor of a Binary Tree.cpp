/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* tmp1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* tmp2 = lowestCommonAncestor(root->right, p, q);
        if(tmp1 == NULL){
            return tmp2;
        }else if(tmp2 == NULL){
            return tmp1;
        }
        return root;
    }
};
/*

* We consider a simplified case: 3 nodes : root, left, right:
* Let's consider that if the root is NULL or root == p or root==q, we should return the root;
* If not, then we search q and p from left children and right children. If we cannot find p and q, then that path will return NULL, which means that that p and q must be in the same side, then we will return the result of the other path.
* If both path is not equal to NULL, then it means that the two nodes are in different path, we directly return the root node.

* So from above analysis, we can divide this problem to smaller problems.
*/
*/
