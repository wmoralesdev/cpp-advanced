#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main(void) {
    auto head = new node();
    auto str = "Hello World";
    auto dec = 2.0;
    auto arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto chr = 'a';

    auto findMin = [](auto a, auto b) {
        return a < b ? a : b;
    };

    auto 

    cout << "Min: " << findMin(10, 11) << endl;

    return 0;
}