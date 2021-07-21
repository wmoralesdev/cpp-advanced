// Obtener cantidad de nodos de una lista
// 4 -> 7 -> 9 -> NULL
// 1 + (  1 + (  1 + ( 0 )  )  )
int size(node* list) {
    if(list)
        return 1 + size(list->next);
    else
        return 0;
}

// Obtener la multiplicacion de los numeros de una lista
double multiply(node* list) {
    if(list)
        return list->data * multiply(list->next);
    else
        return 0;
}

// Mostrar la pos de un nodo
// 4 -> 7 -> 9 -> NULL

/*
    pos = 2, aux = 0
    4 -> 7 -> 9 -> NULL

    pos = 2, aux = 1
    7 -> 9 -> NULL

    pos = 2, aux = 2 -> cout << list->data
    9 -> NULL
*/
void show(node* list, int pos, int aux) {
    if(list) {
        if(pos == aux)
            cout << list->data << endl;
        else
            show(list->next, pos, aux + 1);
    }
}