#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;
typedef struct {
    int size;
    Node* array[MAX_SIZE];
} MinHeap;
Node* createNode(char character, int frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}
MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}
void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}
void insertMinHeap(MinHeap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}
Node* extractMin(MinHeap* heap) {
    Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}
MinHeap* buildMinHeap(char data[], int freq[], int size) {
    MinHeap* heap = createMinHeap();
    for (int i = 0; i < size; i++)
        heap->array[i] = createNode(data[i], freq[i]);
    heap->size = size;
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(heap, i);
    return heap;
}
Node* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* heap = buildMinHeap(data, freq, size);
    while (heap->size != 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}
void generateHuffmanCodes(Node* root, char* code, int top, char codes[MAX_SIZE][MAX_SIZE]) {
    if (root->left) {
        code[top] = '0';
        generateHuffmanCodes(root->left, code, top + 1, codes);
    }
    if (root->right) {
        code[top] = '1';
        generateHuffmanCodes(root->right, code, top + 1, codes);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->character], code);
        printf("%c: %s\n", root->character, code);
    }
}
void countFrequency(const char* message, char* characters, int* frequencies, int* size) {
    int count[MAX_SIZE] = {0};
    for (int i = 0; message[i]; i++)
        count[(unsigned char)message[i]]++;
    *size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            characters[*size] = i;
            frequencies[*size] = count[i];
            (*size)++;
        }
    }
}
void encodeMessage(const char* message, char codes[MAX_SIZE][MAX_SIZE]) {
    printf("\nEncoded Message: ");
    for (int i = 0; message[i]; i++)
        printf("%s", codes[(unsigned char)message[i]]);
    printf("\n");
}
void decodeMessage(const char* encoded, Node* root) {
    printf("\nDecoded Message: ");
    Node* current = root;
    for (int i = 0; encoded[i]; i++) {
        current = (encoded[i] == '0') ? current->left : current->right;
        if (!current->left && !current->right) {
            printf("%c", current->character);
            current = root;
        }
    }
    printf("\n");
}
int main() {
    int choice;
    char message[1024];
    char characters[MAX_SIZE];
    int frequencies[MAX_SIZE];
    char codes[MAX_SIZE][MAX_SIZE] = {0};
    int size;
    Node* root = NULL;
    do {
        printf("\nHuffman Encoding Menu\n");
        printf("1. Input message and generate Huffman codes\n");
        printf("2. Encode a message\n");
        printf("3. Decode a message\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("\nEnter the message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                countFrequency(message, characters, frequencies, &size);
                printf("\nCharacter Frequencies:\n");
                for (int i = 0; i < size; i++)
                    printf("%c: %d\n", characters[i], frequencies[i]);
                root = buildHuffmanTree(characters, frequencies, size);
                printf("\nHuffman Codes:\n");
                char code[MAX_SIZE];
                generateHuffmanCodes(root, code, 0, codes);
                break;
            case 2:
                if (!root) {
                    printf("\nHuffman Tree not generated yet. Please generate it first.\n");
                    break;
                }
                printf("\nEnter the message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message, codes);
                break;
            case 3:
                if (!root) {
                    printf("\nHuffman Tree not generated yet. Please generate it first.\n");
                    break;
                }
                printf("\nEnter the encoded message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message, root);
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}