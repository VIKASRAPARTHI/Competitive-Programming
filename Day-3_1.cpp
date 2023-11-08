#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int key;
    int freq;
    ListNode* next;

    ListNode(int k, int f) : key(k), freq(f), next(nullptr) {}
};

struct TreeNode {
    int key;
    int freq;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k, int f) : key(k), freq(f), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode*& head, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode* leftSubtree = sortedListToBST(head, start, mid - 1);
    TreeNode* root = new TreeNode(head->key, head->freq);
    root->left = leftSubtree;
    head = head->next; 
    root->right = sortedListToBST(head, mid + 1, end);

    return root;
}

int calculateSearchCost(TreeNode* root, int level) {
    if (root == nullptr) {
        return 0;
    }

    return root->freq * level + calculateSearchCost(root->left, level + 1) + calculateSearchCost(root->right, level + 1);
}

int minSearchCost(vector<int>& keys, vector<int>& freq) {
    int n = keys.size();
    ListNode* head = new ListNode(keys[0], freq[0]);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(keys[i], freq[i]);
        current = current->next;
    }
    TreeNode* root = sortedListToBST(head, 0, n - 1);

    int totalCost = calculateSearchCost(root, 1);
    return totalCost;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> keys(n);
        vector<int> freq(n);

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> freq[i];
        }

        int result = minSearchCost(keys, freq);
        cout << result << endl;
    }
    return 0;
}
