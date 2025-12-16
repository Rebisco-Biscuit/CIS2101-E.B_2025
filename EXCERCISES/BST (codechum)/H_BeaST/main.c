#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum length for the key
#define MAX_KEY_LEN 100

// 1. Structure Definition
typedef struct node {
   char *key;          // The string element used for comparison and storage
   struct node* LC;   // Left Child pointer
   struct node* RC;   // Right Child pointer
} Node, *BST;


// iterative
void insert(BST *tree, const char *key_data) {
    // TODO...
    BST *trav = tree;
    
    while(*trav != NULL) {
        int cmp = strcmp(key_data, (*trav)->key);
        if(cmp == 0) {
            printf("Key \"%s\" already exists. Ignoring.\n", (*trav)->key);
            return;
        } else if (cmp < 0) {
            trav = &(*trav)->LC;
        } else {
            trav = &(*trav)->RC;        
        }
    }
    *trav = calloc(1, sizeof(Node));
    (*trav)->key = malloc(strlen(key_data)+1);
    strcpy((*trav)->key, key_data);
    printf("Inserted key: \"%s\"\n", (*trav)->key);
}

// recursive
/*
void insert(BST *tree, const char *key_data) {
    BST *trav = tree;
    
    while(*trav != NULL && strcmp((*trav)->key, key_data) != 0) {
        trav = (strcmp(key_data,(*trav)->key) < 0)? &(*trav)->LC:&(*trav)->RC;
    } 
    
    if(*trav != NULL) {
        printf("Key \"%s\" already exists. Ignoring.\n", (*trav)->key);        
    }
    
    if(*trav == NULL) {
        *trav = calloc(1, sizeof(Node));
        (*trav)->key = malloc(strlen(key_data)+1);
        strcpy((*trav)->key, key_data);
        printf("Inserted key: \"%s\"\n", (*trav)->key);
    }
}
*/


// recursive

void inorderTraversal(BST tree) {
    if(tree != NULL) {
        inorderTraversal(tree->LC);
        printf("\"%s\" ", tree->key);
        inorderTraversal(tree->RC);
    }
    // TODO...
}

// iterative
void preorderTraversal(BST tree) {
    Node *stack[50];
    int top = -1;
    
    Node *current = tree;
    
    while(current != NULL || top != -1) {
        
        while(current != NULL) {
            printf("\"%s\" ", current->key);
            stack[++top] = current;
            current = current->LC;
        }
        
        current = stack[top--];
        current = current->RC;
    }
    // TODO...
}


// recursive
/*
void preorderTraversal(BST tree) {
    if(tree != NULL) {
        printf("\"%s\" ", tree->key);
        preorderTraversal(tree->LC);
        preorderTraversal(tree->RC);        
    }
    // TODO...
}
*/

void postorderTraversal(BST tree) {
    // TODO...
    if(tree != NULL) {
        postorderTraversal(tree->LC);
        postorderTraversal(tree->RC);
        printf("\"%s\" ", tree->key);        
    }
}

/**
 * @brief Frees all memory allocated for the BST nodes, including the string keys.
 * * @param tree The root of the tree to destroy.
 */
void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);

        if (tree->key != NULL) {
            free(tree->key);
        }

        free(tree);
    }
}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Initializing and Inserting String Data into BST ---\n");

    // Root: 'Mango'
    // Left: 'Apple', 'Banana'
    // Right: 'Pineapple', 'Grape', 'Orange', 'Kiwi'
    insert(&myTree, "Mango");
    insert(&myTree, "Apple");
    insert(&myTree, "Pineapple");
    insert(&myTree, "Banana");
    insert(&myTree, "Grape");
    insert(&myTree, "Orange");
    insert(&myTree, "Kiwi");

    // Test duplicate handling
    insert(&myTree, "Mango");

    printf("\n\n--- BST Traversal Results ---\n");

    // In-Order: Sorted (A, B, G, K, M, O, P)
    printf("1. In-Order Traversal (Left-Root-Right, Sorted):\n");
    printf("   ");
    inorderTraversal(myTree);
    printf("\n\n");

    // Pre-Order: Root first (M, A, B, P, G, K, O)
    printf("2. Pre-Order Traversal (Root-Left-Right):\n");
    printf("   ");
    preorderTraversal(myTree);
    printf("\n\n");

    // Post-Order: Root last (B, A, K, O, G, P, M)
    printf("3. Post-Order Traversal (Left-Right-Root):\n");
    printf("   ");
    postorderTraversal(myTree);
    printf("\n\n");

    // 3. Clean up memory
    destroyTree(myTree);
    printf("Tree destroyed and memory freed.\n");

    return 0;
}