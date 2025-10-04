#include <iostream>

using namespace std;


const int size = 10;
int arra[size] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};


int cariminimum() {
    int min_val = arra[0]; 
    for (int i = 1; i < size; i++) {
        if (arra[i] < min_val) {
            min_val = arra[i];
        }
    }
    return min_val;
}


int carimaksimum() {
    int max_val = arra[0];
    for (int i = 1; i < size; i++) {
        if (arra[i] > max_val) {
            max_val = arra[i];
        }
    }
    return max_val;
}


void hitungRataRata() {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arra[i];
    }
    
    
    float rata_rata = (float)total / size; 
    
    cout << "nilai total array: " << total << endl;
    cout << "nilai rata-rata array: " << rata_rata << endl;
}


void tampilkanarray() {
    cout << "Isi Array arra = {";
    for (int i = 0; i < size; i++) {
        cout << arra[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    int pilihan;
    
    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda (1-5): ";
        cin >> pilihan;
        
        cout << "--------------------------" << endl;

       
        switch (pilihan) {
            case 1:
                tampilkanarray();
                break;
            case 2:
                cout << "nilai maksimum: " << carimaksimum() << endl;
                break;
            case 3:
                cout << "nilai minimum: " << cariminimum() << endl;
                break;
            case 4:
                hitungRataRata();
                break;
            case 5:
                cout << "program selesai" << endl;
                break;
            default:
                cout << "pilihan tidak valid Silakan coba lagi" << endl;
                break;
        }
        
    } while (pilihan != 5);

    return 0;
}