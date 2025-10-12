#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};


float hitungnilaiakhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    mahasiswa mhs[10];
    int n;

    cout << "masukkan jumlah mahasiswa (max 10): ";
    cin >> n;
    cin.ignore();

    if (n > 10) {
        cout << "jumlah melebihi batas maksimum (10)!" << endl;
        return 0;
    }

  
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "nama   : ";
        getline(cin, mhs[i].nama);
        cout << "nim    : ";
        getline(cin, mhs[i].nim);
        cout << "nilai uts   : ";
        cin >> mhs[i].uts;
        cout << "nilai ua   : ";
        cin >> mhs[i].uas;
        cout << "nilai tugas : ";
        cin >> mhs[i].tugas;
        cin.ignore(); 

       
        mhs[i].nilaiAkhir = hitungnilaiakhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "nama        : " << mhs[i].nama << endl;
        cout << "nim         : " << mhs[i].nim << endl;
        cout << "uts         : " << mhs[i].uts << endl;
        cout << "uas         : " << mhs[i].uas << endl;
        cout << "tugas       : " << mhs[i].tugas << endl;
        cout << "nilai akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
