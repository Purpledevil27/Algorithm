// https://leetcode.com/problems/diameter-of-binary-tree/

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

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

// Time Complexity - O(N)
class Solution
{
public:
    int height(TreeNode *root, int &dia)
    {
        if (root == NULL)
            return 0;
        int lefDia = height(root->left, dia);
        int rigDia = height(root->right, dia);
        dia = max(dia, lefDia + rigDia);
        // returns the max height
        return max(lefDia, rigDia) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};