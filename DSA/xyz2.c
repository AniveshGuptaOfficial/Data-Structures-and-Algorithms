#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HuffmanNode {
    char data;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct HuffmanNode* newNode(char data) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void decodeHuffman(struct HuffmanNode* root, char* encodedMessage) {
    struct HuffmanNode* current = root;
    int i;

    for (i = 0; encodedMessage[i] != '\0'; i++) {
        if (encodedMessage[i] == '0') {
            current = current->left;
        } else if (encodedMessage[i] == '1') {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root; 
        }
    }
}

int main() {
    char encodedMessage[100];

    scanf("%s", encodedMessage);

    struct HuffmanNode* root = newNode('*');
    root->left = newNode('A');
    root->right = newNode('B');

    decodeHuffman(root, encodedMessage);

    return 0;
}