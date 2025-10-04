#include <iostream>

using namespace std;

void tukar_pointer(int *A, int *B, int *C) {
    int temp;
    temp = *A;
    *A = *C;
    *C = *B;
    *B = temp;
}

void tukar_referensi(int &X, int &Y, int &Z) {
    int temp;
    temp = X;
    X = Z;
    Z = Y;
    Y = temp;
}

int main() {
    int a = 11, b = 16, c = 8;

    cout << " demo call by pointer " << endl;
    cout << "Sebelum ditukar: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar_pointer(&a, &b, &c); 
    
    cout << "Setelah ditukar: a=" << a << ", b=" << b << ", c=" << c << endl;
    
  

    int x = 5, y = 7, z = 4;

    cout << " demo call by reference " << endl;
    cout << "Sebelum ditukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    
    tukar_referensi(x, y, z);
    
    cout << "Setelah ditukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    
    return 0;
}