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
    List* list=(List*) malloc (sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
    return list;// esta buena
}

void * firstList(List * list) {
    if(list->head == NULL) return NULL;
    list->current = list->head;
    return list->head->data;
    //return NULL;//esta buena
}

void * nextList(List * list) {
    if (list->current!=NULL) list->current = list->current->next;
    if (list->current!=NULL) return list->current->data;
    else return NULL;
    //return NULL;//esta buena
}

void * lastList(List * list) {
    //usar ultimo dato
    if(list->tail == NULL) return NULL;
    list->current = list->tail;
    return list->tail->next;//el dato queda como el ultimo de la lista
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {  
    if (list->head != NULL) list->head->data = data;
    list->head = data; 
    
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    Node* aux=list->head;
    while (aux->next != NULL){
        aux = aux->next; 
    }
    Node* newNode = createNode(data);
    aux->next = newNode;
    newNode->prev = aux;

}

void pushCurrent(List * list, void * data) {
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