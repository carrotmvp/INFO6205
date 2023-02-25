#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int main(){

    //input
    int n;
    cin>>n;
    vector<int> treeNum;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        treeNum.push_back(x);
    }

}