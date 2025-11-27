#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> allTrees;
    if (start > end) {
        allTrees.push_back(NULL);
        return allTrees;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    int n = 3; 
    vector<TreeNode*> result = generateTrees(n);

    cout << "Total unique BSTs: " << result.size() << endl;
    for (auto tree : result) {
        printLevelOrder(tree);
    }

    return 0;
}
