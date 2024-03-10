#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int isPerfectFamily(struct TreeNode* root) {
    if (root == NULL) {
        return 1; 
    }

    int children = 0;
    if (root->left != NULL) children++;
    if (root->right != NULL) children++;

    if (children > 1) {
        return 0;
    }

    return isPerfectFamily(root->left) && isPerfectFamily(root->right);
}

int main() {
    int M;
    scanf("%d", &M);  

    struct TreeNode* root = NULL;

    for (int i = 0; i < M; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int result = isPerfectFamily(root);

    printf("%d\n", result);

    return 0;
}
