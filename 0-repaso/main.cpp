// Input - Output Stream en consola
#include <iostream>
// namespace standard -> Contiene todos los comandos std, ejemplo std::cin, std::cout, std::getline
// std::fixed, etc
using namespace std;

void printMenu(void);

// funcion main (siempre debe retornar un valor y ser de tipo int)
int main(void) {
    int option = 0;

    // Declarados como flaot porque division de dos int siempre regresa un int
    float a = 0, b = 0;
    
    /* 
        while -> primero verifica, despues ejecuta el bloque de codigo
        do - whilte -> primero ejecuta el bloque de codigo, luego verifica la condicion
    */
    do {
        printMenu();
        cin >> option;

        switch(option) {
            case 1:
                cin >> a >> b;
                cout << (a + b) << endl;
            break;
            case 2:
                cin >> a >> b;
                cout << (a - b) << endl;
            break;
            case 3:
                cin >> a >> b;
                cout << (a * b) << endl;
            break;
            case 4:
                cin >> a >> b;
                cout << (a / b) << endl;
            break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
            break;
        }

    } while(option != 5);

    // Codigo de salida del programa
    return 0;
}

// firma o prototipo de la funcion
void printMenu(void) {
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: \t";
}