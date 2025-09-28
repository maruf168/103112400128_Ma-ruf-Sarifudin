# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>

## Dasar Teori

### A. Integrated Development Environment (IDE) <br/>
#### 1. Pengertian ide
         Integrated Development Environment (IDE) adalah perangkat lunak yang menyediakan fasilitas komprehensif bagi programmer untuk menulis, mengompilasi, menjalankan, dan men-debug program. Dengan adanya IDE, efisiensi pemrograman dapat ditingkatkan karena semua kebutuhan pengembangan tersedia dalam satu paket terpadu [1]
#### 2. Code::Blocks sebagai IDE
        Code::Blocks merupakan salah satu IDE yang banyak digunakan untuk pemrograman C/C++. IDE ini bersifat open-source, lintas platform, dan mendukung berbagai compiler seperti GCC dan MSVC. Selain itu, Code::Blocks memiliki antarmuka yang sederhana sehingga cocok digunakan dalam pembelajaran pemrograman dasar [2]

### B. Konsep Dasar Pemrograman C++ <br/>
#### 1. Variabel dan Tipe Data
       Variabel adalah media penyimpanan data dalam memori yang diberi nama tertentu. C++ menyediakan berbagai tipe data seperti int, float, double, char, dan bool. Pemilihan tipe data yang tepat akan mempengaruhi efisiensi penggunaan memori dan performa program [3].
       
#### 2.Operator
    C++ memiliki beragam operator, antara lain:
    Operator aritmatika: +, -, *, /, %;
    Operator relasional: ==, !=, <, >;
    Operator logika: &&, ||, !.
     Operator digunakan untuk memanipulasi nilai variabel dan menyusun ekspresi logis maupun matematis [3].

#### 3.Operator     
    Untuk menerima input dari pengguna digunakan objek cin, sedangkan untuk menampilkan keluaran digunakan objek cout, keduanya berasal dari pustaka standar iostream. Mekanisme ini memudahkan interaksi antara program dengan pengguna [4].

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

program ini  berfungsi sebagian penghitungan/ kalkulator  dengan dua inputan bilangan desimal dari pengguna.Setelah menginputkan bilngan desimal program akan melakukan empat operasi aritmatika dasar :pemjumlahan, pengurangan, perkalian, pembagian.program menggunkan cout << setprecision(2) >> untuk mengatur format output bentuknya desimal. program akan menghasilkan output bilangan desimal. 

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

program ini berfungsi unutuk menerjemahkan angka bilangan positif dari 0-100 menjadi bentuk teks (string).program ini menggunakan tiga array(satuan,belasan,Puluhan) untuk menyimpan kata-kata dasar. Semuan logika dilakukan di dalam fungsi terjemahkan(), yang menggunakan pernyataan kondisional if-else unutuk menentukan katagori angka : satuan (0-9), belasan(10-19),puluhan(20-99) dengan memisahkan digit puluhan dan satuan,atau seratus(100).

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
    int n;
    cout << "Input: ";
    cin >> n;

   
    for (int i = n; i >= 1; i--) {

        for (int s = 0; s < n - i; s++) {
            cout << "  "; 
        }

        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        
        cout << "* ";

       
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

  
    for (int s = 0; s < n; s++) {
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

program ini adalah implementasi perulangan bersarang (nested loops) unutuk menghasilkan pola visual kompleks berupa segitiga simetris terbalik menggunakan angka dan simbol bintang. inputan bilangan bulat N unutuk menentukan ukuran pola. Logika utamanya terletak pada perulangan luar yang berjalan mundur dari N hingga 1, yang mengontrol jumlah baris dan membuat pola semakin pendek ke bawah.Di setiap bari, perulangan bersarang pertama mencetak spasi untuk menggeser pola ke kanan, perulangan kedua mencetak angka turun (dari i ke 1), dan dan perulangan ke tiga mencetak angka naik (dari 1 ke i),  dipisahkan oleh bintang (*) di tengahnya. Terakhir kode  bintang terpisah di luar perulangan utama yang mencetak satu baris terakhir berupa bintang tunggal yang diposisikan di tengah, sehingga membentuk bagian penutup pola secara keseluruhan.

## Kesimpulan
Praktikum Modul 1 memperkenalkan penggunaan Code::Blocks sebagai IDE dan dasar pemrograman C++ yang meliputi struktur program, variabel, tipe data, operator, serta mekanisme input dan output. Melalui latihan guided, mahasiswa belajar menulis program sederhana seperti menampilkan teks dan melakukan operasi aritmatika, sedangkan pada latihan unguided mahasiswa dilatih mengembangkan logika sendiri untuk membuat kalkulator sederhana, menerjemahkan angka menjadi teks, dan membentuk pola dengan perulangan. Dengan demikian, praktikum ini memberikan pemahaman awal yang penting sebagai fondasi untuk mempelajari algoritma dan struktur data lebih lanjut.

## Referensi
[1] Setiawan, I. (2022). Komparasi Kinerja Integrated Development Environment (IDE) Dalam Mengeksekusi Perintah Python. SATESI: Jurnal Sains Teknologi dan Sistem Informasi, 2(1), 52-59. 
<br>[2] Putra, D. P., Herlambang, A. D., & Rachmadi, A. (2023). Pengembangan Aplikasi Web IDE berbasis Mobile sebagai Alat Bantu Proses Pembelajaran Pemrograman Web Kelas X TKJ di SMK Cendika Bangsa. Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, 7(7), 3260-3267.
<br>[3] Ma’arif, A. (2021). Dasar pemrograman bahasa C++ [Buku ajar]. Universitas Ahmad Dahlan.
<br>[4] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

