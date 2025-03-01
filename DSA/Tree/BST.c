#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} *Bintree;
Bintree makenode(int item) {
    Bintree root = (Bintree)malloc(sizeof(struct node));
    root->left = root->right = NULL;
    root->data = item;
    return root;
}
Bintree Insert(Bintree t, int data) {
    if (!t)
        return makenode(data);
    if (t->data > data)
        t->left = Insert(t->left, data);
    else
        t->right = Insert(t->right, data);
    return t;
}  
int Search(Bintree t, int data) {
    if (!t) return 0;
    if (t->data == data) return 1;
    if (t->data > data)
        return Search(t->left, data);
    return Search(t->right, data);
} 
void Inorder(Bintree root) {
    if (root != NULL) {
        Inorder(root->left);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}
void Preorder(Bintree root) {
    if (root) {
        printf(" %d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(Bintree root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ", root->data);
    }
}
int findMin(Bintree t) {
    if (!t->left)
        return t->data;
    return findMin(t->left);
}
Bintree deleteVal(Bintree t, int val) {
    if (t) {
        if (t->data == val) {
            if (!t->left && !t->right) return NULL;
            if (!t->left) return t->right;
            if (!t->right) return t->left;
            t->data = findMin(t->right);
            t->right = deleteVal(t->right, t->data);
            return t;
        }
        if (t->data > val)
            t->left = deleteVal(t->left, val);
        else
            t->right = deleteVal(t->right, val);
    }
    return t;
}
int main() {
    Bintree root = NULL;
    int choice, item, n, res;
    do {
        printf("\nBinary Search Tree Operations");
        printf("\n1. Creation of BST");
        printf("\n2. Search in BST");
        printf("\n3. Traverse in Inorder");
        printf("\n4. Traverse in Preorder");
        printf("\n5. Traverse in Postorder");
        printf("\n6. Deletion in BST");
        printf("\n7. Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            root = NULL;
            printf("\nBST for how many nodes? ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                printf("Enter data for node %d: ", i);
                scanf("%d", &item);
                root = Insert(root, item);
            }
            printf("BST with %d nodes is ready to use!!\n", n);
            break;
        case 2:
            printf("\nSearch for which node? ");
            scanf("%d", &n);
            res = Search(root, n);
            if (res)
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 3:
            printf("\nBST Traversal in INORDER\n");
            Inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nBST Traversal in PREORDER\n");
            Preorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nBST Traversal in POSTORDER\n");
            Postorder(root);
            printf("\n");
            break;
        case 6:
            printf("\nDelete which node? ");
            scanf("%d", &n);
            root = deleteVal(root, n);
            printf("\nDeleted\n");
            break;
        case 7:
            printf("\nTerminating\n");
            break;
        default:
            printf("\nInvalid Option !!! Try Again !!\n");
            break;
        }
    } while (choice != 7);
    return 0;
}
