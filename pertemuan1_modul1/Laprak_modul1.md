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
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/C:\Users\HP\OneDrive\Documents\telkomuniversity\strukturdata\praktikumSD\minggu1\laprak\103112400128_Ma-ruf-Sarifudin\pertemuan1_modul1/ss-unguided1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. Soal unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s,d 100.
contoh : 79 : tujuh puluh sembilan 

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

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
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
