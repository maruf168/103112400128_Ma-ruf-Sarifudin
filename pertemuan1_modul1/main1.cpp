#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    float angka1, angka2;
    float penjumlahan, pengurangan, perkalian, pembagian;

    cout << "Masukkan angka1 : ";
    cin >> angka1;
    
    cout << "Masukkan angka2 : ";
    cin >> angka2;
    
    
    penjumlahan = angka1 + angka2; 
    pengurangan = angka1 - angka2; 
    perkalian = angka1 * angka2;   
    pembagian = angka1 / angka2;   

    
    cout << "\nHasil Perhitungan:" << endl;
    
    cout << fixed << setprecision(2);
    
   
    cout << "Penjumlahan (" << angka1 << " + " << angka2 << ") = " << penjumlahan << endl;      
    cout << "Pengurangan (" << angka1 << " - " << angka2 << ") = " << pengurangan << endl;   
    cout << "Perkalian (" << angka1 << " * " << angka2 << ") = " << perkalian << endl;    
    cout << "Pembagian (" << angka1 << " / " << angka2 << ") = " << pembagian << endl;

    return 0;
}