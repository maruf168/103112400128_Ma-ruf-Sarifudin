# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
#include <iostream>

using namespace std;

int main() {
    cout << "Hallo Dunia";
    return 0;
}
```
penjelasan singkat guided 1

### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {

  int angka1, angka2;
  cout << "masukan angka 1 : ";
  cin >> angka1;
  cout << " masukan angka 2: ";
  cin >> angka2;

  //penjumlahan
  cout << " penjumlahan : " << angka1 + angka2 << endl;
  // pengurangan
  cout << " pengurangan  : " << angka1 - angka2 << endl;
  //perkalian
  cout << " perkalian : " << angka1 * angka2 << endl;
  //pembagian 
  cout << " pembagian  : " << angka1 / angka2 << endl;
  //modulus
  cout << " modulus  : " << angka1 % angka2 << endl;
 return 0;
}
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 4. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

### 5. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua  buah bilangan bertipe float,kemudian menerima output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided11.png)

penjelasan unguided 1 

### 2. Soal unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s,d 100.
contoh : 79 : tujuh puluh sembilan 

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided2.png)


##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided22.png)

penjelasan unguided 2

### 3. Soal unguided 3

Buatlah program yang dapat memberikan inputan dan output sbb
input : 3
output:
321 * 123
 21 * 12
  1 * 1
    *

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided3.png)



##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan1_modul1/ss-unguided33.png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
