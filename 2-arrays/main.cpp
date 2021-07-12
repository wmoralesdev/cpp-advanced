#include <iostream>
using namespace std;

void fillArray(float* array, int students);
void printArray(float* array, int students);

int main(void) {
    // // Declarar un arreglo estatico con su tama;io
    // int array[10];

    // // Declarar un arreglo estatico con sus elementos iniciales
    // int arrayElement[] = { 1, 2, 3, 4, 5 };

    int students = 0;
    cin >> students;
    // // Arreglo estatico en tiempo de ejecucion
    // float grades[students];

    // Arreglo dinamico -> Reservado en tiempo de ejecucion
    float* dynamicGrades = new float(students);

    fillArray(dynamicGrades, students);
    printArray(dynamicGrades, students);
    
    return 0;
}

// void staticArray(int array[10]) {

// }

// void staticArray5(int array[5]) {

// }

void fillArray(float* array, int students) {
    for(int i = 0; i < students; i++)
        cin >> array[i];
}

void printArray(float* array, int students) {
    for(int i = 0; i < students; i++)
        cout << array[i] << "\t";
    cout << endl;
}