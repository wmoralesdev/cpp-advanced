#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node() : next(NULL) {}
    node(int d) : data(d), next(NULL) {}
};

void enqueue(node **head, int data);
int size(node* head);
bool isEmpty(node* head);
int last(node* head);
int top(node* head);
int dequeue(node **head);
void show(node* head);

int main(void) {
    node *head = NULL;

    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);

    show(head);

    dequeue(&head);
    dequeue(&head);

    show(head);

    return 0;
}

// enqueue -> O(n)
void enqueue(node **head, int data) {
    //                                          C1 + C2 + C3 + C4 + nC5 + nC6 + C7
    //                                          C + nC5 + nC6 -> C + nV -> Ax + B -> An + B
    //                                          C + O(n) -> O(n)

    // Ejemplo                                  O(1) + O(n) + O(n log n) -> O(n log n)
    node* newNode = new node(data); // 1        C1 = C1

    if (*head == NULL) {            // 1        C2 = C2
        *head = newNode;            // 0 - 1    C3 = C3
    }
    else {
        node* aux = *head;          // 1        C4 = C4

        while(aux->next)            // N        C5 = nC5
            aux = aux->next;        // N        C6 = nC6

        aux->next = newNode;        // 1        C7 = C7
    }
}

// dequeue
int dequeue(node **head) {
    // Obtener la informacion del elemento al inicio
    int data = (*head)->data;

    // Quitar la referencia del inicio, hacia su siguiente pos
    (*head) = (*head)->next;

    // Retornar el dato que estaba al inicio
    return data;
}

// peek
int top(node* head) {
    return head->data;
}

// last - tail
int last(node* head) {
    while(head->next)
        head = head->next;

    return head->data;
}

// isEmpty
bool isEmpty(node* head) { return (head == NULL); }

// size
int size(node* head) {
    if(head)
        return 1 + size(head->next);
    else
        return 0;
}

void show(node* head) {
    if(head) {
        cout << head->data << "\t";
        show(head->next);
    }
    else
        cout << endl << endl;
}