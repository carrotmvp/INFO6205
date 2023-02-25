#include <bits/stdc++.h>
using namespace std;

/*
test 1:
5
1 2 3 4 5

test 2:
0


test 3:
1
1
1

*/

struct TreeNode
{ // struct
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *upsideDownBinaryTree(TreeNode *root)
{ // func
    if (!root || !root->left)
        return root;
    TreeNode *cur_left = root->left;
    TreeNode *cur_right = root->right;
    TreeNode *new_root = upsideDownBinaryTree(root->left);
    cur_left->right = root;
    cur_left->left = cur_right;
    root->left = nullptr;
    root->right = nullptr;
    return new_root;
}

int main()
{
    // input
    int n;
    cin >> n;
    vector<int> treeNum;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "null")
            treeNum.push_back(-1);
        else
            treeNum.push_back(stoi(x));
    }

    // construct a tree
    queue<TreeNode *> que;
    TreeNode *root = new TreeNode(treeNum[0]);
    que.push(root);
    int i = 1; // tag for total number
    while (!que.empty() && i < n)
    {
        TreeNode *node = que.front();
        que.pop();
        for (int j = 1; j <= 2; j++, i++)
        {
            if (treeNum[i] == -1 && j == 1)
                node->left = nullptr;
            else if (treeNum[i] == -1 && j == 2)
                node->right = nullptr;
            else if (j == 1)
            {
                node->left = new TreeNode(treeNum[i]);
                que.push(node->left);
            }
            else
            {
                node->right = new TreeNode(treeNum[i]);
                que.push(node->right);
            }
        }
    }

    root = upsideDownBinaryTree(root); // upside down

    // show the tree
    vector<int> ans;
    queue<TreeNode *> que1;
    i = 0;
    que1.push(root);
    while (!que1.empty())
    {
        TreeNode *node = que1.front();
        i++;
        que1.pop();
        if (node != nullptr)ans.push_back(node->val);
        else ans.push_back(-1);

        if(node->left!=nullptr)que1.push(node->left);
        if(node->right!=nullptr)que1.push(node->right);
    }
    cout << '[';
  
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
            cout << "null" << ' ';
        else
            cout << ans[i] << ' ';
    }
    cout << ']' << endl;
}