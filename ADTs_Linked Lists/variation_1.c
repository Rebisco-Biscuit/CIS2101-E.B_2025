#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize();
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);

int main() {
    List *L = initialize();
    insertFirst(L, 2);
    insertFirst(L, 1);
    insertLast(L, 3);
    insertPos(L, 4, 3);
    insertPos(L, 5, 1);
    deleteStart(L);
    
    return 0;
}

List* initialize()  {
    List *L = malloc(sizeof(List));
    if(L == NULL) {
        return NULL;
    }
    L->head = NULL;
    L->count = 0;
    return L;
}

void deleteStart(List *list) {
  if(list != NULL) {
    Node *current = list->head;
    list->head = current->next;
    free(current);
    
    list->count--;
  }
}

void insertPos(List *list, int data, int index) {
  if(index <= list->count) {
    if(index == list->count) { 
      insertLast(list, data);
    } else if(index == 0) {
      insertFirst(list, data);
    } else {
      Node *newNode = malloc(sizeof(Node));
      newNode->data = data;
      newNode->next = NULL;
      Node *current = list->head;
      for(int i=0; i<index-1; i++) { 
        current = current->next; 
      }
      newNode->next = current->next;
      current->next = newNode;
      list->count++;
    }
  }
}

void insertLast(List *list, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
  
    if(list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;
}

void insertFirst(List *list, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}