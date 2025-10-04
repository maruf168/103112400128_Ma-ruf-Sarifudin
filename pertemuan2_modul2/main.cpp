#include <iostream>

using namespace std;

const int N = 3; 

void penjumlahan(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pengurangan(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalian(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void tampilkan_matriks(int M[N][N], const char* nama) {
    cout << "matriks " << nama << " (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int A[N][N] = {
        {9, 2, 5},
        {3, 5, 4},
        {7, 8, 5}
    };
    
    int B[N][N] = {
        {5, 9, 2},
        {6, 8, 4},
        {2, 6, 9}
    };

    int C[N][N];

    tampilkan_matriks(A, "A");
    tampilkan_matriks(B, "B");

    penjumlahan(A, B, C);
    tampilkan_matriks(C, "hasil penjumlahan (A + B)");

    pengurangan(A, B, C);
    tampilkan_matriks(C, "hasil pengurangan (A - B)");

    perkalian(A, B, C);
    tampilkan_matriks(C, "hasil perkalian (A x B)");

    return 0;
}