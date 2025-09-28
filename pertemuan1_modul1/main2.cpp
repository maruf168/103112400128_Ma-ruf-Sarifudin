#include <iostream>
#include <string>
using namespace std;

string Satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string Belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string Puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

string terjemahkan(int n) {
    if (n < 0 || n > 100) {
        return "Angka di luar dari 0 - 100";
    }
    
    if (n < 10) {
        return Satuan[n];
    } 
    else if (n < 20) {
        return Belasan[n - 10];
    }
    else if (n < 100) {
        int p = n / 10;
        int s = n % 10;

        if (s == 0) {
            return Puluhan[p];
        } else {
            return Puluhan[p] + " " + Satuan[s];
        }
    }
    else {
        return "seratus";
    }
}

int main() {
    int angka;

    cout << "Masukkan angka bulat positif (0-100): ";
    cin >> angka;
    
    string hasil = terjemahkan(angka);
    
    cout << endl;
    cout << angka << " : " << hasil << endl;

    return 0;
}