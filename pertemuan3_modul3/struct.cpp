#include <iostream>;
using namespace std;

struct  mahasiswa{
string nama;
float nilai1, nilai2;
};

void inputMhs (mahasiswa &m){
cout <<"Masukan nama Mahasiswa : ";
cin >> m.nama;
cout <<"Masukan nilai 1: ";
cin >> m.nilai2;
cout << "Masukan nilai 2 : ";
cin >> m.nilai2;
}

float rata2(mahasiswa m) {
return (m.nilai1 + m.nilai2)/2;
}

int main() {
mahasiswa mhs;  //panggilan(ADT)
inputMhs(mhs);  // panggilan prosedur
cout << "Rata - Rata :" << rata2(mhs); //panggilan function
return 0;
}