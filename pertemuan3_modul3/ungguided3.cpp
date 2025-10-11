#include <iostream>
using namespace std;

const int N = 3;


void tampilArray(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}


void tukarPosisi(int A[N][N], int B[N][N], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}


void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A awal:" << endl;
    tampilArray(A);
    cout << "\nArray B awal:" << endl;
    tampilArray(B);

  
    int baris = 1, kolom = 2;
    tukarPosisi(A, B, baris, kolom);

    cout << "\nSetelah menukar elemen pada posisi [" << baris << "][" << kolom << "]:" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "\nArray B:" << endl;
    tampilArray(B);

   
    int x = 100, y = 200;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
