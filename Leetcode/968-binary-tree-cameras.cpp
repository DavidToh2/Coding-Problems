
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res[3];
        mc(root, res);
        return *min_element(res, res + 2);
    }

    /*
    Let mc(p) denote the minimum set of cameras needed to achieve each of the three cases with the
    subtree rooted at p:
    - the entire subtree is covered and there is a camera at p
    - the entire subtree is covered and there is no camera at p
    - the entire subtree, except for p itself, is covered
    Let the children of p be v0, v1. Then
    - mc(p)[0] = 1 + min(mc(v0)) + min(mc(v1))
        - This is because, for this subcase, the subtrees rooted at v1 and v2 can be in any state - in
        fact, v1 and v2 themselves do not yet need to be covered
    - mc(p)[1] = min(mc(v0)[0] + mc(v1)[1], mc(v0)[1] + mc(v1)[0], mc(v0)[0] + mc(v1)[0])
        - This is because, for this subcase, there must either be a camera at v1 or a camera at v2; and
        both subtrees rooted at v1, v2 must be fully covered
    - mc(p)[2] = mc(v0)[1] + mc(v1)[1]
        - For this subcase, there cannot be any cameras at v1 or v2
    */
    void mc(TreeNode* root, int res[]) {
        if (!root) { res[0] = 1e7; res[1] = 0; res[2] = 0; return; }
        int v0[3]; int v1[3];
        mc(root->left, v0); mc(root->right, v1);

        res[0] = 1 + *min_element(v0, v0+3) + *min_element(v1, v1+3);
        int arr1[3] = {
            v0[0] + v1[1], v0[1] + v1[0], v0[0] + v1[0]
        };
        res[1] = *min_element(arr1, arr1+3);
        res[2] = v0[1] + v1[1];
        return;
    }
};