#include <stdlib.h>
#include <stdio.h>

/* trying out for-loops for traversal instead of while */

/*

ll ACCESSED BY VALUE
ll ACCESSED BY VALUE
ll ACCESSED BY VALUE

*/

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

//create operations
List initialize(List);
List insertFirst(List, int);
List insertLast(List, int);
List insertPosition(List, int, int);

//delete operations
List empty(List);
List deleteStart(List);
List deleteLast(List);
List deletePos(List, int);

//display operations
int retrieve(List, int);
int locate(List, int);
void printList(List);

int main() {
  List l;
  l = initialize(l);
  
  l = insertFirst(l, 1);
  // l = insertFirst(l, 2);  
  // l = insertLast(l, 3);
  // l = insertFirst(l, 5);  
  // l = insertLast(l, 4);  
  l = insertPosition(l, 2, 0);
  l = insertLast(l, 64);  
  
  l = empty(l);
  


    return 0;
}

//display operations
int retrieve(List list, int idx) {
  if(idx < 0 || idx > list.count || list.head == NULL) { return -1; }

  else {
    Node *trav = list.head;
    for(int i=0; i != idx && trav != NULL; i++, trav = trav->next) {}
    return trav->data;
  }
}

int locate(List list, int data) {
  if(list.head == NULL) { return -1; }

  else {
    Node *trav = list.head;
    int i=0;
    for(; i < list.count && trav->next != NULL && trav->data != data; i++, trav = trav->next) {}
    return i;
  }
}

void printList(List list) {
  if(list.head == NULL) { printf("List is empty.\n"); return; }

  else {
      while(list.head != NULL) {
        printf("%d -> ", list.head->data);
        list.head = list.head->next;
      }
      printf("NULL\n");
  }
}

//create operations
List initialize(List list) {
  list.head = NULL;
  list.count = 0;
  return list;
}

List insertFirst(List list, int data) {
  
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  
  if(list.head == NULL) {
    list.head = newNode;
  } else {
    newNode->next = list.head;
    list.head = newNode;
  }
  list.count++;
  return list;
}

List insertLast(List list, int data) {
  
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  
  if(list.head == NULL) {
    list.head = newNode;
    
  } else {
  
    Node *trav = list.head;
    
    while(trav->next != NULL) {
      trav = trav->next;
    }
    trav->next = newNode;
  
  }
  list.count++;
  return list;
}

List insertPosition(List list, int data, int idx) {
  if(idx > list.count || idx < 0 || list.head == NULL) { return list; }
  else if(idx == 0) { list = insertFirst(list, data); }
  else if(idx == list.count) { list = insertLast(list, data); }
  
  else {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    Node *trav = list.head;
    
    for(int i=0; i < idx-1 && trav->next != NULL; i++, trav = trav->next) {}
    newNode->next = trav->next;
    trav->next = newNode;
    
    list.count++;
  }
  
  return list;
}

//delete operations
List deleteStart(List list) {
  if(list.head == NULL) { return list; }
  Node *temp = list.head;
  list.head = temp->next;
  free(temp);
  
  list.count--;
  
  return list;
}

List deleteLast(List list) {
  if(list.head == NULL) { return list; }
  
  else if(list.count == 1) { list = deleteStart(list); }
  
  else {
    Node *trav = list.head;
    
    for(int i=0; i < list.count-2 && trav->next != NULL; i++, trav = trav->next) {}
    free(trav->next);
    trav->next = NULL;
    list.count--;
  }
  
  return list;
}

List deletePos(List list, int idx)  {
  if(idx > list.count || idx < 0 || list.head == NULL) { return list; }
  else if(idx == 0) { list = deleteStart(list); }
  else if(idx == list.count) { list = deleteLast(list); }
  
  else {
    Node *trav = list.head;
    for(int i=0; i < idx-1 && trav->next != NULL; i++, trav = trav->next) {}
    Node *temp = trav->next;
    trav->next = temp->next;
    free(temp);
    
    list.count--;
  }
  return list;
}

List empty(List list) {
  if(list.head == NULL) { return list; }
  for(int i=list.count; i >= 0; i--) {
    list = deleteLast(list);
  }
  return list;
}