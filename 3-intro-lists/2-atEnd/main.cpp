// Cola - Queue
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node(int d) : data(d), next(NULL) {}
};

int main(void) {
    node* head = NULL;
    int option = 0;

    do {
        int aux = 0;
        cout << "Num: "; cin >> aux;

        node* newNode = new node(aux);
        
        if(!head)
            head = newNode;
        else {
            node* aux = head;

            // 1 -> 2 -> 3 -> 5 -> NULL
            while(aux->next) {
                aux = aux->next;
            }

            aux->next = newNode;
        }

        cout << "Add a new node? (1/0): "; cin >> option;
    } while(option != 0);

    //  ; Condicion    ; Incremento-Cambio
    for(; head != NULL; head = head->next) {
        cout << head->data << "\t";
    }
    cout << endl;

    return 0;
}