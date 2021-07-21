#include <iostream>
using namespace std;

// Generic template
// Easiest implementation

template<class Info>
struct node {
    // Info
    Info data;

    // Enlaces
    node<Info>* next;

    // Metodos (Constructores)
    node() : next(NULL) {}
    node(Info _data) : data(_data), next(NULL) {}
};

template<class Info>
struct list {
    node<Info>* head;
    node<Info>* tail;

    list() {
        head = new node<Info>();
        tail = new node<Info>();
    }
};

int main(void) {
    list<int> integers;

    push(&integers, 9);

    auto deletePredicate = [](auto element) -> bool {
        return element < 10;
    };

    deleteAll(&integers, deletePredicate);

    return 0;
}

template<class Info>
void push(list<Info>* list, Info data) {            // O(1)
    node<Info>* newNode = new node<Info>(data);     // 1

    if(!list->head)                                 // 1
        list->head = list->tail = newNode;          // 0 - 1
    else {
        newNode->next = list->head;                 // 0 - 1
        list->head = newNode;                       // 0 - 1
    }
}

template<class Info>
void pushBack(list<Info>* list, Info data) {        // O(1)
    node<Info>* newNode = new node<Info>(data);     // 1

    if(!list->head)                                 // 1
        list->head = list->tail = newNode;          // 0 - 1
    else {
        list->tail->next = newNode;                 // 0 - 1
        list->tail = newNode;                       // 0 - 1
    }
}

template<class Info>
Info peek(list<Info>* list) {
    return list->head->data;
}

template<class Info>
Info last(list<Info>* list) {
    return list->tail->data;
}

template<class Info>
void deleteFront(list<Info>* list) {
    list->head = list->head->next;

    if(!list->head)
        list->tail = NULL;
}

template<class Info>
void deleteBack(list<Info>* list) {
    node<Info>* aux = list->head;

    while(aux->next->next)      // O(n)
        aux = aux->next;

    aux->next = NULL;
    list->tail = aux;
}

template<class Info>
void deleteIndex(list<Info>* list, int index) {
    node<Info>* aux = list->head;
    int count = 0;

    // 1 - 4 - 7 - 8 - 9
    while(aux->next && count != index)
        aux = aux->next;
    
    if(aux)
        aux->next = aux->next->next;
}

template<class Info, class Pred>
void deleteAll(list<Info>* list, Pred pred) {
    if(list->head) {
        if(pred(list->head->data))
            // Delete
        else
            deleteAll(list->head->next, pred);
    }
}