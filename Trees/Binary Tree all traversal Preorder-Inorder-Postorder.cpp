// Time complexity - O(3N) & Space complexity - O(3N)

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
    void binaryTreeTraversals(TreeNode *root)
    {
        if (root == NULL)
            return;
        vector<int> preorder, inorder, postorder;
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        while (!s.empty())
        {
            auto p = s.top();
            s.pop();
            if (p.second == 1)
            {
                preorder.push_back(p.first->val);
                s.push({p.first, p.second + 1});
                if (p.first->left)
                {
                    s.push({p.first->left, 1});
                }
            }
            else if (p.second == 2)
            {
                inorder.push_back(p.first->val);
                s.push({p.first, p.second + 1});
                if (p.first->right)
                {
                    s.push({p.first->right, 1});
                }
            }
            else
            {
                postorder.push_back(p.first->val);
            }
        }
        cout << "Preorder - ";
        for (auto &i : preorder)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Inorder - ";
        for (auto &i : inorder)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "Postorder - ";
        for (auto &i : postorder)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
