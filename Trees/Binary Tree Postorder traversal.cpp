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

// Itertive approach
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *top = s.top();
            s.pop();

            if (top->left)
            {
                s.push(top->left);
            }
            if (top->right)
            {
                s.push(top->right);
            }
            ans.push_back(top->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Itertive approach #2
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *curr = root;
        while (curr != NULL || !s.empty())
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = s.top()->right;
                if (!temp)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while (!s.empty() && temp == s.top()->right)
                    {
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};

// Iterative Approach #3
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *curr = s.top();
            if (curr->left)
            {
                s.push(curr->left);
                curr->left = NULL;
            }
            else
            {
                if (curr->right)
                {
                    s.push(curr->right);
                    curr->right = NULL;
                }
                else
                {
                    ans.push_back(curr->val);
                    s.pop();
                }
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
        find(root->left, ans);
        find(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        find(root, ans);
        return ans;
    }
};