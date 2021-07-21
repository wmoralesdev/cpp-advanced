// Pila - Stack
#include <iostream>
using namespace std;

// Ejemplo de estructura
// struct coordinate {
//     int x, y;

//     coordinate() {}

//     coordinate(int _x, int _y) {
//         this->x = _x;
//         this->y = _y;
//     }
// };

struct node {
    int data;
    node* next;

    node() {
        next = NULL;
    }

    node(int _data) : data(_data) {
        next = NULL;
    }
};

void print(node* head);
void printModified(node** head);

int main(void) {
    node* head = NULL;

    int option = 0;

    do {
        int aux = 0;
        cout << "data: "; cin >> aux;

        // Insercion al inicio de una lista
        node* n = new node(aux);
        
        if(!head) {
            head = n;
        }
        else {
            n->next = head;
            head = n;
        }

        cout << "More data: "; cin >> option;
    } while (option != 0);

    node* head1 = head, *head2 = head;

    print(head);
    cout << endl;

    printModified(&head);
    cout << endl;

    while(head) {
        cout << head->data << "\t";
        head = head->next;
    }
    cout << endl;

    //  Inicia    Condi   Incremento-Cambio
    for(int i = 0; i < 5; i++) {
        cout << i << "\t";
    }
    cout << endl;

    //  ; Condicion    ; Incremento-Cambio
    for(; head1 != NULL; head1 = head1->next) {
        cout << head1->data << "\t";
    }
    cout << endl;

    return 0;
}

// Enviar un puntero por valor
void print(node* head) {
    while(head) {
        cout << head->data << "\t";
        head = head->next;
    }
}

void printModified(node** head) {
    while(*head) {
        cout << (*head)->data << "\t";
        *head = (*head)->next;
    }
}

/*
    Lista vacia
    HEAD
    DATO0 -> NULL

    Lista con elementos
    DATO4 -> HEAD

             HEAD
    DATO4 -> DATO1 -> DATO2 -> DATO3 -> NULL

    HEAD
    DATO4 -> DATO1 -> DATO2 -> DATO3 -> NULL
*/