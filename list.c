#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * lista = (List *)malloc(sizeof(List));
  return lista;
}

void * firstList(List * list) {
  list->current = list->head;
  if (list->current) 
    return list->current->data;
  else
    return NULL;
}

void * nextList(List * list) {
  if (list->current)
    list->current = list->current->next;
  if (list->current)
    return list->current->data;
  else
    return NULL;
}

void * lastList(List * list) {
  list->current = list->tail;
  if (list->current)
    return list->current->data;
  else
    return NULL;
}

void * prevList(List * list){
  if (list->current)
    list->current = list->current->prev;
  if (list->current)
    return list->current->data;
  else
    return NULL;
}

void pushFront(List * list, void * data) {
  Node* newNode = createNode(data);
  newNode->next = list->head;
  if (list->head)
    list->head->prev = newNode;
  list->head = newNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  /*Node* newNode = createNode(data);
  newNode->next = list->current->next;
  newNode->prev = list->current;
  if (list->current->next)
    list->current->next->prev = newNode;
  list->current->next = newNode;*/
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}