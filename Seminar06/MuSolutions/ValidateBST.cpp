#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// BST check using min/max nodes
bool isBST(Node* node, Node* minNode, Node* maxNode) {
    if (!node) return true;
    if ((minNode && node->value <= minNode->value) ||
        (maxNode && node->value >= maxNode->value))
        return false;
    return isBST(node->left, minNode, node) &&
           isBST(node->right, node, maxNode);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << 1 << "\n"; // empty tree is BST
            continue;
        }

        vector<Node*> nodes(n);
        vector<int> leftIdx(n), rightIdx(n);

        for (int i = 0; i < n; i++) {
            int val, l, r;
            cin >> val >> l >> r;
            nodes[i] = new Node(val);
            leftIdx[i] = l;
            rightIdx[i] = r;
        }

        // Connect children
        for (int i = 0; i < n; i++) {
            if (leftIdx[i] != -1) nodes[i]->left = nodes[leftIdx[i]];
            if (rightIdx[i] != -1) nodes[i]->right = nodes[rightIdx[i]];
        }

        Node* root = nodes[0];

        if (isBST(root, nullptr, nullptr))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";

        for (Node* node : nodes) delete node;
    }

    return 0;
}
