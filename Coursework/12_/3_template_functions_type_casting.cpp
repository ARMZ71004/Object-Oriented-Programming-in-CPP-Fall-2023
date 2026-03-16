// S. Trowbridge 2023
#include <iostream>
using namespace std;

template<typename T>
void swapVal(T &a, T &b) {              // T must be the same type in all places     
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << endl;

    int x = 1;
    double y = 5.4;

    cout << x << " " << y << "\n";
    swapVal(x, y);                      // compiler error: cannot automatic type cast int to a double or vice versa like a regular function
    cout << x << " " << y << "\n";

    cout << endl;
    return 0;
}
