#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node(int d) : data(d), next(NULL) {}
};

int main(void) {

}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    } 
}

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[right - left + 1];

    // Mientras que el arreglo izq tenga elementos && el derecho tenga elementos
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
    }
}

int size(node *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + size(head->next);
}

// 1 -> NULL
// NULL

/*
    1 rec
    arr = 4, 6, 1, 3, 2, 9, 0, -1

    size = 8
    mid = 4

    left = 4, 6, 1, 3
    right = 2, 9, 0, -1

        2 rec
        left = mergeSort(left) -> 1, 3, 4, 6
            arr = 4, 6, 1, 3

            size = 4
            mid = 2

            left = 4, 6
            right = 1, 3

            3 rec
            left = mergeSort(left) -> 4, 6
                arr = 4, 6

                size = 2
                mid = 1

                left = 4
                right = 6

                4 rec
                left = mergeSort(left)
                    return arr;

                left = 4

                5 rec
                right = mergeSort(right)
                    return arr;

                arr = merge(left, right)

            6 rec
            right = mergeSort(right) -> 1, 3
                arr = 1, 3

                size = 2
                mid = 1

                left = 1
                right = 3

                7 rec
                left = mergeSort(left)
                    return arr;

                8 rec
                right = mergeSort(right)
                    return arr;

                arr = merge(left, right)

            arr = merge(left, right)
    
        9 rec
        right = mergeSort(right) -> -1, 0, 2, 9
            arr = 2, 9, 0, -1
            
            size = 4
            mid = 2

            left = 2, 9
            right = 0, -1

            10 rec
            left = mergeSort(left) -> 2, 9
                arr = 2, 9

                size = 2
                mid = 1

                left = 2
                right = 9

                11 rec
                left = mergeSort(left)
                    return arr;

                12 rec
                right = mergeSort(right)
                    return arr;

            13 rec
            right = mergeSort(right) -> -1, 0
                arr = 0, -1

                size = 2
                mid = 1

                14 rec
                left = mergeSort(left)
                    return arr;

                15 rec
                right = mergeSort(right)
                    return arr;

            arr = merge(left, right)

    end rec
    arr = merge(left, right) -> -1, 0, 1, 2, 3, 4, 6, 9
*/

node* mergeSort(node* arr) {
    if(arr == NULL || arr->next == NULL) {
        return arr;
    }
    else {
        int sizeArr = size(arr);
        int mid = sizeArr / 2;

        node* left = NULL;
        for(int i = 0; i < mid; i++) {
            push(&left, arr->data);
        }

        node* right = NULL;
        for(int i = mid + 1; i < sizeArr; i++) {
            push(&right, arr->data);
        }

        left = mergeSort(left);
        right = mergeSort(right);

        arr = merge(left, right);
    }
}

node* merge(node* left, node* right) {
    node* merged = NULL;

    // left = NULL
    // right = 13

    // merged = 1 -> 3 -> 4 -> 6 -> 7 -> 10 -> 12

    while(left != NULL && right != NULL) {
        if(left->data <= right->data) {
            push(&merged, left->data);
            left = left->next;
        }
        else {
            push(&merged, right->data);
            right = right->next;
        }
    }

    // left = NULL
    // right = 13 -> 15 -> 20 -> 22

    // merged = 1 -> 3 -> 4 -> 6 -> 7 -> 10 -> 12 -> 13

    while(left != NULL) {
        push(&merged, left->data);
    }

    while(right != NULL) {
        push(&merged, right->data);
    }
}


// MergeSort(arr[], l,  r)
//      If r > l
//      1. Find the middle point to divide the array into two halves:  
//              middle m = l+ (r-l)/2
//      2. Call mergeSort for first half:   
//              Call mergeSort(arr, l, m)
//      3. Call mergeSort for second half:
//              Call mergeSort(arr, m+1, r)
//      4. Merge the two halves sorted in step 2 and 3:
//              Call merge(arr, l, m, r)

// Merge(arr[], l, m, r)
//      1. Initialize variables
//      2. Create two empty subarrays to store the sorted subarrays:
//              left[] and right[]
//      3. Initialize left and right index:
//              i = l, j = m+1
//      4. Loop until one of the two arrays becomes empty:
//              a) If i is greater than or equal to m, copy the remaining elements of right subarray to left subarray:
//                      Copy the remaining elements of right subarray to left subarray:
//                              while (j <= r)
//                                      left[i++] = right[j++]
//              b) If j is greater than or equal to r, copy the remaining elements of left subarray to right subarray:
//                      Copy the remaining elements of left subarray to right subarray:
//                              while (i <= m)
//                                      right[j++] = left[i++]
//      5. Copy the elements of left subarray to arr[l..r]

