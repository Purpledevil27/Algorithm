// Time complexity - O(N) & Space complexity - O(N)

// https://leetcode.com/problems/binary-tree-inorder-traversal

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

// Using Recursion - Approach #1
class Solution
{
public:
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, ans);
        ans.emplace_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Using Stack - Iterative Approach (#2)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        s.push(root);
        while (!s.empty())
        {
            TreeNode *top = s.top();
            if (top->left)
            {
                s.push(top->left);
                top->left = NULL;
            }
            else
            {
                ans.push_back(top->val);
                s.pop();
                if (top->right)
                {
                    s.push(top->right);
                }
            }
        }
        return ans;
    }
};

// Using Stack - Iterative Approach (#3)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        TreeNode *node = root;
        while (true)
        {
            if (node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};