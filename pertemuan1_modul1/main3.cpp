#include <iostream>

using namespace std;

int main() {
    int N;
    int i, j;

    cout << "Masukkan input N: ";
    cin >> N;

    cout << "\nOutput:\n";
    for (i = N; i >= 1; i--) {
        
       
        for (j = 1; j <= N - i; j++) {
            cout << "  ";
        }

       
        for (j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        
        cout << "*"; 

        
        for (j = 2; j <= i; j++) {
            cout << " " << j;
        }
        
        cout << endl;
    }

    
    for (i = 1; i <= N; i++) {
        cout << "  ";
    }
    
    
    cout << "*" << endl;

    return 0;
}