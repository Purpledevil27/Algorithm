// https://www.geeksforgeeks.org/iterative-preorder-traversal-of-a-n-ary-tree/

// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

// Time complexity - O(N) & Space complexity - O(N)

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// Iteratively
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *top = s.top();
            s.pop();
            ans.push_back(top->val);
            for (int i = top->children.size() - 1; i >= 0; i--)
            {
                s.push(top->children[i]);
            }
        }
        return ans;
    }
};

// Recursively
class Solution
{
    void find(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        for (auto &i : root->children)
        {
            find(i, ans);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        find(root, ans);
        return ans;
    }
};