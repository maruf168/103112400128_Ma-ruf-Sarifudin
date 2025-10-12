# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>

## Dasar Teori

### A. Operasi Matriks (3x3) <br/>
         Matriks adalah susunan bilangan yang disusun dalam bentuk baris dan kolom. Banyak digunakan dalam komputasi karena dapat menampilkan data, transformasi linear, dan persamaan matematis. [1]
         Jika dua matriks memiliki ordo yang sama dan prosesnya dilakukan elemen per elemen, penjumlahan dan pengurangan matriks hanya dapat dilakukan jika keduanya memiliki aturan dimensi yang sama. Perkalian matriks dilakukan dengan mengalikan baris matriks pertama dengan kolom matriks kedua, yang menghasilkan matriks baru dengan ordo yang berbeda sesuai dengan aturan dimensi.
         Representasi matriks dalam pemrograman C++ biasanya menggunakan array dua dimensi dan perulangan bersarang, juga dikenal sebagai nested loop, untuk mengakses dan mengubah elemen matriks.[2]


### B. Pointer dan Reference <br/>
      Salah satu variabel adalah pointer, yang menyimpan alamat memori dari variabel lain. Karena pointer bekerja langsung dengan alamat memori, sebuah fungsi memiliki kemampuan untuk mengubah nilai variabel asli. Sementara itu, referensi, atau alias, adalah nama variabel yang sudah ada, yang juga memungkinkan perubahan langsung pada variabel asli melalui mekanisme panggil dengan referensi.
      Karena keduanya memungkinkan perubahan nilai di luar fungsi, pointer dan referensi digunakan secara luas dalam pertukaran nilai (swap). Perbedaan utama antara referensi dan pointer adalah bahwa referensi harus diinisialisasi secara langsung pada saat deklarasi dan tidak dapat diubah referensinya.[3]
       
#### C.Array 1 Dimensi dan Operasi Statistik Dasar
    Array adalah struktur data yang menyimpan sekumpulan elemen bertipe sama dalam satu blok memori yang berurutan. Array satu dimensi hanya memerlukan satu indeks untuk mengakses elemen di dalamnya 
    Beberapa operasi penting yang sering dilakukan pada array antara lain:
        -Mencari nilai minimum, yaitu membandingkan seluruh elemen untuk menemukan nilai terkecil.
        -Mencari nilai maksimum, dengan cara serupa tetapi mencari nilai terbesar.
        -Menghitung rata-rata, yaitu menjumlahkan seluruh elemen kemudian membaginya dengan banyaknya elemen.
    Operasi-operasi dasar ini sering dipadukan dengan struktur kontrol seperti switch-case untuk membuat program menu interaktif, sehingga pengguna dapat memilih jenis operasi yang ingin dijalankan [4].


## Guided 

### 1. Implementasi Array dengan Perulangan For dan While 

```C++
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
```
Program ini berfungsi untuk menampilkan penerapan struktur data mahasiswa yang menyimpan nama dan dua nilai ujian, lalu menghitung rata-ratanya. Prosedur inputMhs() digunakan untuk menerima input data dari pengguna, sedangkan fungsi rata2() menghitung nilai rata-rata dari dua nilai yang dimasukkan. Program ini memanggil kedua fungsi dan menampilkan hasil perhitungan rata-rata ke layar, sehingga menggambarkan penggunaan struct, prosedur, dan fungsi secara terintegrasi.

### 2. Program Operasi Matriks 2x2

```C++
##1.pelajaran.h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>

using namespace std;

//Deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
}; 
//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodeMapel); 

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

##2. pelajaran.cpp

#include "pelajaran.h"

//tampilkan function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//tampilkan prosedur tampilkan_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama Pelajaran :" <<pel.namaMapel << endl;
    cout << "kode pelajaran :" <<pel.kodeMapel << endl;
}


##3.main.cpp

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```
Fungsi program ini adalah untuk mendemonstrasikan operasi penjumlahan dan perkalian pada dua Matriks 2x2. Program ini menginisialisasi dua array dua dimensi (arrA dan arrB) yang bertindak sebagai matriks. Program menggunakan fungsi void bernama tampilkanHasil untuk mencetak array hasil dengan rapi. Operasi penjumlahan dilakukan dengan dua perulangan bersarang, menjumlahkan elemen pada indeks yang sama. Sementara itu, operasi perkalian menggunakan tiga perulangan bersarang (untuk baris, kolom, dan perkalian elemen) untuk menghitung hasil kali skalar baris arrA dengan kolom arrBS.



## Unguided 

### 1. Soal Unguided 1

Buatlah program yang dapat menyimpan data mahasiswa (Max 10) kedalam sebuah array dengan field nama,nim,uts,uas,tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
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
        cout << "nilai uas   : ";
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


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided1.png)




penjelasan unguided 1 

Fungsi program ini adalah untuk menyimpan, menghitung, dan menampilkan data nilai beberapa mahasiswa secara terstruktur. Program ini menggunakan struct, array, fungsi, perulangan for, dan percabangan if. Struktur mahasiswa digunakan untuk menyimpan data seperti nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Data beberapa mahasiswa disimpan dalam array mhs[10], sedangkan fungsi hitungnilaiakhir() digunakan untuk menghitung nilai akhir berdasarkan bobot UTS, UAS, dan tugas. Proses input dan output dilakukan menggunakan perulangan for agar dapat membaca serta menampilkan data setiap mahasiswa secara berulang, sementara percabangan if digunakan untuk membatasi jumlah mahasiswa maksimal 10 orang.

### 2. Soal unguided 2

Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h".m
type pelajaran <
     namaMapel : string
     kodeMapel : string
>
fungction create_pelajaran( namapel : string,
     kodepel : string ) -> pelajarn
procedure tampil_pelajaran( input pel : pelajaran)

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp
Coba hasil implementasi ADT pada file "main.cpp

using namespace std;
int main() {
    string namapel = "struktur data";
    string kedepel = "STD";
    string pel = create_pelajaran(namapel,kodepel);
    tampil_pelajaran(pel);

    return 0;
}

contoh output hasil

nama pelajaran = struktur Data
nilai : STD

```C++

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided2.png)


##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided22.png)

penjelasan unguided 2

Tentu, program C++ ini berfungsi untuk mendemonstrasikan dua cara berbeda untuk memodifikasi nilai variabel di luar fungsi (Call by Pointer dan Call by Reference) melalui operasi penukaran nilai melingkar (circular swap) pada tiga variabel.
Tentu, program C++ ini berfungsi untuk mendemonstrasikan dua cara berbeda untuk memodifikasi nilai variabel di luar fungsi (Call by Pointer dan Call by Reference) melalui operasi penukaran nilai melingkar (circular swap) pada tiga variabel.

Program ini mendefinisikan dua fungsi (tukar_pointer dan tukar_referensi) yang masing-masing:
 1.Menggunakan Call by Pointer: Fungsi tukar_pointer menerima alamat memori variabel. Fungsi ini memodifikasi nilai variabel asli dengan menggunakan operator dereferensi (*) pada parameter yang dilewatkan.
 2.Menggunakan Call by Reference: Fungsi tukar_referensi menerima referensi variabel (int &X). Fungsi ini memodifikasi nilai variabel asli tanpa menggunakan operator dereferensi.
 Kedua fungsi tersebut mengimplementasikan logika penukaran melingkar (A mengambil nilai C, C mengambil nilai B, dan B mengambil nilai A) dengan bantuan variabel sementara (temp).

### 3. Soal unguided 3

Buarlah program dengan ketentuan :
1. 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
2. Fungsi/prosedur yang meampilkan isi sebuah array integer 2D
3. Fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
4. Fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

const int N = 3;


void tampilArray(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}


void tukarPosisi(int A[N][N], int B[N][N], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}


void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A awal:" << endl;
    tampilArray(A);
    cout << "\nArray B awal:" << endl;
    tampilArray(B);

  
    int baris = 1, kolom = 2;
    tukarPosisi(A, B, baris, kolom);

    cout << "\nSetelah menukar elemen pada posisi [" << baris << "][" << kolom << "]:" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "\nArray B:" << endl;
    tampilArray(B);

   
    int x = 100, y = 200;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "Setelah tukar pointer:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}


```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided3.png)



penjelasan unguided 3

Fungsi program ini adalah untuk menampilkan dan menukar elemen-elemen dalam dua array dua dimensi (matriks) serta mendemonstrasikan pertukaran nilai menggunakan pointer. Program ini menggunakan array 2 dimensi, fungsi, perulangan for, dan pointer. Dua matriks A dan B berukuran 3×3 diinisialisasi dengan nilai berbeda, kemudian fungsi tampilArray() digunakan untuk menampilkan isi masing-masing matriks. Fungsi tukarPosisi() berfungsi menukar elemen pada posisi tertentu antara kedua matriks menggunakan variabel sementara (temp). Selain itu, fungsi tukarPointer() digunakan untuk menukar nilai dua variabel melalui alamat memori menggunakan pointer. Dengan kombinasi elemen-elemen tersebut, program ini menunjukkan cara kerja array dua dimensi, perulangan bersarang, dan manipulasi data melalui pointer.

## Kesimpulan

Praktikum Modul 2 memperdalam pemahaman mahasiswa mengenai penggunaan array, pointer, reference, serta perulangan dalam C++. Melalui latihan guided, mahasiswa berlatih mengimplementasikan operasi dasar seperti manipulasi array, operasi matriks, dan variasi loop. Pada latihan unguided, mahasiswa mengembangkan logika mandiri untuk membuat program operasi matriks 3x3, pertukaran nilai dengan pointer dan reference, serta analisis statistik array menggunakan menu interaktif. Praktikum ini melatih kemampuan problem solving sekaligus membangun dasar penting untuk mempelajari algoritma dan struktur data lanjutan.

## Referensi
[1] Pratama, H. J., Ali, E. P., Nurvia, M., & Harahap, E. (2021). Aplikasi penjumlahan dan perkalian matriks pada microsoft excel. Matematika: Jurnal Teori dan Terapan Matematika, 20(1), 17-22. 
<br>[2] Nuraini, R. (2015). Desain algorithma operasi perkalian matriks menggunakan metode flowchart. Jurnal teknik komputer, 1(1), 144-151.
<br>[3] Ma’arif, A. (2021). Dasar pemrograman bahasa C++ [Buku ajar]. Universitas Ahmad Dahlan.
<br>[4] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

