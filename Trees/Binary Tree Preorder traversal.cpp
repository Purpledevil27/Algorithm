// https://www.geeksforgeeks.org/iterative-preorder-traversal/

// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Time complexity - O(N) & Space complexity - O(N)

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

// Iterative approach
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            ans.push_back(t->val);
            if (t->right)
            {
                s.push(t->right);
            }
            if (t->left)
            {
                s.push(t->left);
            }
        }
        return ans;
    }
};

// Recursive approach
class Solution
{
public:
    void find(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->val);
        find(root->left, ans);
        find(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        find(root, ans);
        return ans;
    }
};
