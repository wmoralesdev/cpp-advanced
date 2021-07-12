// Punteros, paso por valor y por referencia

#include <iostream>
using namespace std;

// En todos los lenguajes - Con tipos de datos primitivos
void changeNumber(int a);

void changeNumberByPointer(int* a);

int changeWithReturnValue(void);

void changeNumberByRef(int& a);

int main(void) {
    int number = 10;

    cout << "Before: " << number << endl;
    changeNumber(number);
    cout << "After: " << number << endl;

    cout << "Before: " << number << endl;
    changeNumberByPointer(&number);
    cout << "After: " << number << endl;

    cout << "Before: " << number << endl;
    changeNumberByRef(number);
    cout << "After: " << number << endl;

    cout << "Before: " << number << endl;
    number = changeWithReturnValue();
    cout << "After: " << number << endl;

    return 0;
}

void changeNumber(int a) {
    a = 20;
}

void changeNumberByRef(int& a) {
    a = 30;
}

void changeNumberByPointer(int* a) {
    // a -> Direccion de memoria a la cual esta apuntando
    // *a -> Valor contenido en la direccion de memoria a la cual esta apuntando
    cout << "Pos at: " << a << endl;
    *a = 20;
}

int changeWithReturnValue(void) {
    return 20;
}