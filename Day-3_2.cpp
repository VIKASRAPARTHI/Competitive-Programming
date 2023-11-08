#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return nullptr;
    }

    TreeNode* node = new TreeNode(nodes[index]);
    index++;
    node->left = buildTree(nodes, index);
    node->right = buildTree(nodes, index);

    return node;
}

int findMaxDepth(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftDepth = findMaxDepth(node->left);
    int rightDepth = findMaxDepth(node->right);

    return max(leftDepth, rightDepth) + 1;
}

int main() {
    vector<int> nodes;
    int nodeValue;
    while (cin >> nodeValue) {
        nodes.push_back(nodeValue);
    }

    int startNode;
    cin >> startNode;

    int index = 0;
    TreeNode* root = buildTree(nodes, index);

    int maxDepth = findMaxDepth(root);
    int burningTime = maxDepth - 1;

    cout << burningTime << endl;

    return 0;
}
