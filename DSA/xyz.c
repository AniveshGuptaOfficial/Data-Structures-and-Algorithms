#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HuffmanNode {
    char symbol;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct MinHeap {
    int size;
    int capacity;
    struct HuffmanNode** array;
};

struct HuffmanNode* createHuffmanNode(char symbol, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HuffmanNode**)malloc(capacity * sizeof(struct HuffmanNode*));
    return minHeap;
}

void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&minHeap->array[index], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

struct HuffmanNode* buildHuffmanTree(char symbols[], int frequencies[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, createHuffmanNode(symbols[i], frequencies[i]));
    }

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createHuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    scanf("%d", &size);

    char symbols[size];
    int frequencies[size];

    for (int i = 0; i < size; i++) {
        scanf(" %c", &symbols[i]); 
        scanf("%d", &frequencies[i]);
    }

    struct HuffmanNode* root = buildHuffmanTree(symbols, frequencies, size);

    int arr[100], top = 0;
    printHuffmanCodes(root, arr, top);

    return 0;
}