#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(void) {
    int arr[] = { 9, -1, 10, 1, 5, 2, 8, 3, 4, 4, 4, 9, 10 };

    quickSort(arr, 0, 12);

    for(int i = 0; i < 13; i++)
        cout << arr[i] << "\t";

    cout << endl;
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}