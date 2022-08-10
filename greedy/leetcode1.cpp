#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return -1;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    int isBalanced(TreeNode *root)
    {
        return getHeight(root->left) - getHeight(root->right);
    }
    TreeNode *rightRotate(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = temp->right;
        temp->right = getRotation(root);
        return getRotation(temp);
    }
    TreeNode *leftRotate(TreeNode *root)
    {
        TreeNode *temp = root->right;
        root->right = temp->left;
        temp->left = getRotation(root);
        return getRotation(temp);
    }

    TreeNode *getRotation(TreeNode *root)
    {
        int bal = isBalanced(root);
        if (bal >= 2)
        {
            if (isBalanced(root->left) >= 1)
                return rightRotate(root);
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (bal <= -2)
        {
            if (isBalanced(root->right) <= -1)
                return leftRotate(root);
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == nullptr)
            return NULL;
        root->left = balanceBST(root->left);
        root->right = balanceBST(root->right);
        return getRotation(root);
    }
};