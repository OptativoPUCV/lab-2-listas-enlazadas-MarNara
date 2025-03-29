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
    list->current = list->tail;//el dato que esta mostrando
    return list->tail->data;
}

void * prevList(List * list) {
    if (list->current!=NULL) list->current = list->current->prev;
    if (list->current!=NULL) return list->current->data;
    return NULL;
}

void pushFront(List * list, void * data) {  
    //Node* newNode =(Node*)malloc(sizeof(Node));
    //if(newNode == NULL) return;
    Node* newNode = createNode(data);
    newNode->data = data;//asignar el dato al nuevo nodo
    newNode->prev = NULL;//que el prev del nuevo nodo sea nulo
    newNode->next = list->head;
    //aqui inserto al inicio.
    if(list->head) list->head->prev = newNode;
    list->head = newNode; 
    //me falta analizar si solo hay un dato (el que yo ingrese)
    if(list->head->next == NULL){
        list->tail = newNode;
    }
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
    /*crear un nuevo nodo y dar ese nombre al dato que quiero agregar y luego al previo del nuevo nodo le asigno el current*/
    Node* newNode = createNode(data);
    newNode->data = data;
    //if(list->current == NULL) return;
    newNode->prev = list->current;//el previo es el dato que apunta el current
    newNode->next = list->current->next;//el siguiente es el siguiente del current
    if(list->current->next != NULL){
        list->current->next->prev = newNode;//el siguiente del previo es el nuevo nodo
    }
    list->current->next = newNode;
    
    if(list->current == list->tail){
        list->tail = newNode;
    }
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
    
    Node* izq = list->current->prev;
    Node* der = list->current->next;
    if(list->current == NULL) return;
    izq->next = der;
    der->prev = izq;
    
    if(list->current == list->head ){
        list->head = der;// es decir que es el siguiente
        list->head->prev = NULL;

    }
    if(list->current == list->tail){
        list->tail = izq;
        list->tail->next = NULL;
    }
    list->current->next = der;

    free(list->current);
    
    //return list->current;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}