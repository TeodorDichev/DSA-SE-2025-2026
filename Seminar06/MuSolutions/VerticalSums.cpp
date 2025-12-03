#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void dfs(Node* node, int x, map<int,long long>& sums) {
    if (!node) return;
    sums[x] += node->value;
    dfs(node->left, x - 1, sums);
    dfs(node->right, x + 1, sums);
}

int main() {
    int n;
    cin >> n;
    if (n == 0) return 0;

    vector<Node*> nodes(n);
    vector<int> leftIdx(n), rightIdx(n);

    for (int i = 0; i < n; i++) {
        int val, l, r;
        cin >> val >> l >> r;
        nodes[i] = new Node(val);
        leftIdx[i] = l;
        rightIdx[i] = r;
    }

    for (int i = 0; i < n; i++) {
        if (leftIdx[i] != -1) nodes[i]->left = nodes[leftIdx[i]];
        if (rightIdx[i] != -1) nodes[i]->right = nodes[rightIdx[i]];
    }

    Node* root = nodes[0];

    map<int,long long> sums;
    dfs(root, 0, sums);

    for (auto& [x, sum] : sums)
        if (sum != 0) cout << sum << " ";
    cout << endl;

    for (Node* node : nodes) delete node;
    return 0;
}
