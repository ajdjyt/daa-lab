#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

Node* newNode(char data, unsigned freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

int compare(const void* a, const void* b) {
    Node* n1 = *(Node**)a;
    Node* n2 = *(Node**)b;
    return n1->freq - n2->freq;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    Node* nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = newNode(data[i], freq[i]);
    }
    qsort(nodes, size, sizeof(Node*), compare);
    while (size > 1) {
        left = nodes[0];
        right = nodes[1];
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        nodes[0] = top;
        for (int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        size--;
        qsort(nodes, size, sizeof(Node*), compare);
    }
    return nodes[0];
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) 
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = buildHuffmanTree(arr, freq, size);
    int codes[100], top = 0;
    printCodes(root, codes, top);
    return 0;
}
