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

//create operations
List* initialize();
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);

//display operations
int retrieve(List *list, int index);
int locate(List *list, int data);
void printList(List *list);

//delete operations
void empty(List *list);
void deletePos(List *list, int index);
void deleteLast(List *lsit);
void deleteStart(List *list);

int main() {
    List *L = initialize();
    insertFirst(L, 2);
    insertFirst(L, 1);
    insertLast(L, 3);
    empty(L);
    // insertPos(L, 4, 3);
    //deletePos(L, 2);
    // printf("%d\n", retrieve(L, 3));
    // printf("%d\n", locate(L, 1));
    // printf("%d\n", locate(L, 2));
    // printf("%d\n", locate(L, 3));   
    // printList(L);
    
    // insertPos(L, 5, 1);
    // deleteStart(L);
    //deleteLast(L);
    
    return 0;
}

//display operations
int locate(List *list, int data) {
  if(list->head == NULL){ return -1; }
  else {
    //int idx=0;
    Node *current = list->head;
    for(int i=0; i<list->count-1; i++){
      if(current->data == data) { return i; }
      current = current->next;
    }
  }
  return -1;
}

int retrieve(List *list, int index) {
  if(index < list->count-1) {
    index -= 1;
    Node *current = list->head;
    for(int i=0; i<=index-1; i++) {
      current = current->next;
    }
    return current->data;
  }
  return -1;
}

void printList(List *list) {
  Node *current = list->head;
  while(current!= NULL) {
    printf(" %d ->", current->data);
    current = current->next;
  }
  printf(" NULL");
}

//delete operations
void empty(List *list) {
  for(int i=list->count; i > 0; i--) {
    deleteLast(list);
  }
}

void deleteLast(List *list) {
  if(list->count == 1) {
    deleteStart(list);
  } else {
    Node *current = list->head;
    for(int i=0; i<list->count-2; i++) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->count--;
  }
}

void deleteStart(List *list) {
  if(list != NULL) {
    Node *current = list->head;
    list->head = current->next;
    free(current);
    
    list->count--;
  }
}

void deletePos(List *list, int index) {
  if(index == 0) {
    deleteStart(list);
  } else if (index == list->count) {
    deleteLast(list);
  } else {
    Node *current = list->head;
    for(int i=0; i<index-1; i++) {
      current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    
  }
}

//create operations
List* initialize()  {
    List *L = malloc(sizeof(List));
    if(L == NULL) {
        return NULL;
    }
    L->head = NULL;
    L->count = 0;
    return L;
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
      for(int i=0; i<index; i++) { 
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