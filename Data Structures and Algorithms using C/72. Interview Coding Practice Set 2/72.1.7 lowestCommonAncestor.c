#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node != NULL) {
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createTreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

struct TreeNode* bst(char values[][10], int size) {
    struct TreeNode* root = NULL;
    if (values == NULL)
        return NULL;

    for (int i = 0; i < size; ++i) {
        if (strcmp(values[i], "null") != 0) {
            if (root == NULL) {
                root = createTreeNode(atoi(values[i]));
            } else {
                insert(root, atoi(values[i]));
            }
        }
    }
    return root;
}

struct TreeNode* find(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;
    else if (val < root->val)
        return find(root->left, val);
    else
        return find(root->right, val);
}

struct TreeNode* lca(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val > root->val && q->val > root->val)
        return lca(root->right, p, q);
    else if (p->val < root->val && q->val < root->val)
        return lca(root->left, p, q);
    else
        return root;
}

int main() {
    char values[100][10];
    int count = 0;
    while (1) {
        scanf("%s", values[count]);
        if (strcmp(values[count], "-1") == 0)
            break;
        count++;
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct TreeNode* root = bst(values, count);
    if (root == NULL) {
        return 0;
    }

    struct TreeNode* p = find(root, p_val);
    struct TreeNode* q = find(root, q_val);
    if (p == NULL || q == NULL) {
        return 0;
    }

    struct TreeNode* lca_node = lca(root, p, q);

    printf("%d\n", lca_node->val);

    return 0;
}