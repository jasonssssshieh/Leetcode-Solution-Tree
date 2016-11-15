/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
 //2016-11-04复习
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l < 0 || r < 0 || abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l < 0 || r < 0 || abs(l - r) > 1) return -1;
        return 1 + max(l,r);
    }
};
 
/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){return true;}
        int h1 = dfs(root->left);
        int h2 = dfs(root->right);
        if(h1<0 || h2<0 || abs(h1-h2)>1){return false;}
        else {return isBalanced(root->left)&&isBalanced(root->right);}
        }
        
private:
   int dfs(TreeNode* root){
       if(root == NULL){return 0;}
       int h1 = dfs(root->left);
       int h2 = dfs(root->right);
       if(h1<0 || h2<0 || abs(h1-h2)>1){return -1;}
       else{return 1+max(h1,h2);}
   }
 };*/
/*
问题：判断二叉树是否为平衡二叉树
分析：树上的任意结点的左右子树高度差不超过1，则为平衡二叉树。
         搜索递归，记录i结点的左子树高度h1和右子树高度h2，则i结点的高度为max(h1,h2)=1，|h1-h2|>1则不平衡
http://blog.csdn.net/feliciafay/article/details/18348065

http://www.cnblogs.com/zsboy/p/3889661.html
*/
