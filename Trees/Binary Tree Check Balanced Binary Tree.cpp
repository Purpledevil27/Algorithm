// https://leetcode.com/problems/balanced-binary-tree/

// A binary tree is balanced if the height of its left subtree and right subtree is less than 2

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity - O(N)
class Solution
{
    int isBalancedhelper(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = isBalancedhelper(root->left);
        if (left == -1)
            return -1;
        int right = isBalancedhelper(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (isBalancedhelper(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

// Time complexity - O(N^2)
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(height(root->left), (height(root->right))) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        return (abs(hl - hr) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};