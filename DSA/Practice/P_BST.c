#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} *Bintree;

Bintree makenode(int data){
    Bintree root = (Bintree)malloc(sizeof(struct node));
    root->left=root->right = NULL;
    root->data=data;
    return root;
}

Bintree insert(Bintree root,int data){
    if(!root) return makenode(data);
    if(root->data>data) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}

int search(Bintree root,int data){
    if(!root) return 0;
    if(root->data==data) return 1;
    if(root->data>data) return search(root->left,data);
    return search(root->right,data);
}

void Inorder(Bintree root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(Bintree root){
    if(root){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(Bintree root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}

int findmin(Bintree root){
    if(!root->left)
        return root->data;
    return findmin(root->left);
}

Bintree delete(Bintree root,int val){
    if(root){
        if(root->data==val){
            if(!root->left && !root->right) return 0;
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            root->data = findmin(root->right);
            root->right = delete(root->right,root->data);
            return root;
        }
        if(root->data>val)
            root->left = delete(root->left,val);
        else
            root->right = delete(root->right,val);
    }
    return root;
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
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter number of nodes: ");
                scanf("%d", &n);
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &item);
                    root = insert(root, item);
                }
                break;
            case 2:
                printf("\nEnter element to search: ");
                scanf("%d", &n);
                res = search(root, n);
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
                scanf("%d",&n);
                root=delete(root,n);
                printf("Delete");
                break;
            default:
                printf("\nInvalid Option !!! Try Again !!\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
