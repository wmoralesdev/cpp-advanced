#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node() {}

    node(int d) : data(d), next(NULL) {}
};

int pop(node** stk);
int top(node* stk);
int size(node* stk);
void show(node* stk);
bool isEmpty(node* stk);
void push(node** stk, int data);
void copy(node* stk, node** newStk);

int main(void) {
    node* stk = NULL;

    // Push
    cout << "Push" << endl;
    push(&stk, 3);
    push(&stk, 2);
    push(&stk, 1);
    cout << endl;

    // Pop
    cout << "Pop" << endl;
    cout << "Pop: " << pop(&stk) << endl;
    push(&stk, 5);
    cout << "Pop: " << pop(&stk) << endl;
    cout << endl;

    // Peek - Top
    cout << "Peak - Top" << endl;
    cout << "Top: " << top(stk) << endl;
    cout << endl;

    //Empty - isEmpty
    cout << "Empty" << endl;
    cout << "Empty: " << (isEmpty(stk) ? "true" : "false") << endl;
    cout << endl;

    // Size
    cout << "Size" << endl;
    cout << "Size: " << size(stk) << endl;
    cout << endl;

    // Copy
    cout << "Copy" << endl;
    node* newStk = NULL;
    copy(stk, &newStk);

    // Show
    cout << "Stk\t"; show(stk);
    cout << "NewStk\t"; show(newStk);

    cout << endl;

    return 0;
}

// Agregar elementos a una pila -> O(1)
// 1. Retornar la pila modificada                   - Valor de retorno
// 2. No retornar nada y modificar en la funcion    - Punteros (doble)
void push(node** stk, int data) {
    node* newNode = new node(data);

    newNode->next = *stk;
    *stk = newNode;
}

// Eliminar el elemento al tope de la pila
int pop(node** stk) {
    // Obtener la informacion del elemento al inicio
    int data = (*stk)->data;

    // Quitar la referencia del inicio, hacia su siguiente pos
    (*stk) = (*stk)->next;

    // Retornar el dato que estaba al inicio
    return data;
}

// Consultar el elemento al tope de la pila
int top(node* stk) {
    return stk->data;
}

// Consultar si la pila esta vacia
bool isEmpty(node* stk) {
    return stk == NULL;
}

// Consultar la cantidad de elementos de una pila
int size(node* stk) {
    if(stk)
        return 1 + size(stk->next);
    else
        return 0;
}

// Copiar los contenidos de una pila a otra
void copy(node* stk, node** newStk) {
    // Pila original
    // 1 4 2 3

    // Pila copia - Insercion como cola
    // 1 4 2 3
    while(stk) {
        node* newNode = new node(pop(&stk));

        if(isEmpty(*newStk))
            *newStk = newNode;
        else {
            node* aux = *newStk;

            while(aux->next)
                aux = aux->next;

            aux->next = newNode;
        }
    }
}

void show(node* stk) {
    if(stk) {
        cout << stk->data << "\t";
        show(stk->next);
    }
    else
        cout << endl;
}