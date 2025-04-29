#include<stdio.h>
struct TreeNode {

    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertBST(struct TreeNode* root, int key) {
    if (root == NULL) {
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->data = key;
        root->left = root->right = NULL;
        return root;
    }
    if (key < root->data) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}
