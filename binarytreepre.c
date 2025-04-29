struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
