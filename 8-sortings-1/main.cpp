#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n) {               // O(n^2)
    for (int i = 0; i < n; i++) {               // n + 1
        for (int j = 0; j < n - 1; j++) {       // n
            if (a[j] > a[j + 1]) {              // n
                int temp = a[j];                // n
                a[j] = a[j + 1];                // n
                a[j + 1] = temp;                // n
            }
        }
    }
}

// Selection Sort (Ascending)

/*
    Ordenar el arreglo encontrando repetidamente el elemento minimo, luego se pasa al inicio
*/
void selectionSort(int a[], int n) {        // O(n^2) -> O(n^1.9898980)
    int i = 0, j = 0, minIndex = 0;
    
    for (int i = 0; i < n - 1; i++) {
        // Asumir que estamos en el elemento mas pequeno
        minIndex = i;

        // Recorrer desde el siguiente al minimo, hasta el final
        for (int j = i + 1; j < n; j++) {

            // Si el elemento actual es menor que el minimo, se cambia el indice
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }

            // Desplazar el elemento i hacia el indice del minimo
            swap(a[i], a[minIndex]);
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}