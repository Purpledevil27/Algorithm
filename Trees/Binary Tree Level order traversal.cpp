// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);

        vector<int> temp;
        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            if (front == NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if (!pendingNodes.empty())
                {
                    pendingNodes.push(NULL);
                }
                continue;
            }
            temp.push_back(front->val);
            if (front->left)
            {
                pendingNodes.push(front->left);
            }
            if (front->right)
            {
                pendingNodes.push(front->right);
            }
        }
        return ans;
    }
};