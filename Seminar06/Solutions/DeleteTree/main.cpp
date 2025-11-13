struct Node
{
    int data;
    Node* left;
    Node* right;
};

void free(const Node* root)
{
    if(!root) return;

    free(root->left);
    free(root->right);
    delete root;
}