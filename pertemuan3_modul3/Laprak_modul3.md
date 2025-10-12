# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>

## Dasar Teori

### A.Abstract Data Type (ADT) <br/>
        Abstract Data Type (ADT) atau tipe data abstrak merupakan konsep dalam pemrograman yang mendefinisikan sekumpulan operasi yang dapat dilakukan pada suatu tipe data tanpa harus mengetahui bagaimana data tersebut disimpan atau diimplementasikan. ADT berfungsi sebagai bentuk abstraksi untuk menyembunyikan detail implementasi dan hanya menampilkan antarmuka yang digunakan oleh pengguna program. Dengan pendekatan ini, pemrogram dapat memisahkan antara cara penggunaan data dan cara penyimpanan data secara internal.[1]


### B.Struktur Data dan Modularitas dalam ADT <br/>
     Dalam penerapannya, ADT sering diimplementasikan menggunakan struct atau class di bahasa C++, di mana atribut menyimpan data dan fungsi/prosedur digunakan untuk mengakses serta memanipulasi data tersebut. Pendekatan ini memungkinkan pemrogram untuk menerapkan prinsip enkapsulasi, yakni melindungi data agar tidak diakses langsung dari luar modul.[2]
       
#### C.Keuntungan Penggunaan ADT dalam Pemrograman
    Penggunaan ADT dalam pemrograman memberikan beberapa keuntungan, antara lain kemudahan dalam memperbaiki dan memperbarui kode tanpa memengaruhi bagian lain dari program, peningkatan keamanan data melalui pembatasan akses langsung, serta peningkatan efisiensi dalam pengelolaan struktur data kompleks seperti stack, queue, dan linked list. ADT sering diimplementasikan menggunakan struct atau class. Struct menyimpan data (field), sedangkan fungsi/prosedur menyediakan operasi-operasi terhadap data tersebut, seperti create, tampil, swap, dan sebagainya.[2]


## Guided 

### 1. Struct ADT 

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

### 2. program file pelajaran.h

```C++

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


```
Fungsi program ini untuk mendefinisikan Abstract Data Type (ADT) bernama pelajaran yang digunakan sebagai cetakan data untuk menyimpan informasi mata pelajaran. Program ini menggunakan struct, fungsi, dan prosedur, serta menerapkan konsep header file (.h) dalam pemrograman modular. Di dalam struktur pelajaran, terdapat dua atribut yaitu namaMapel dan kodeMapel yang masing-masing bertipe string. Selain itu, file ini juga mendeklarasikan sebuah fungsi create_pelajaran() yang digunakan untuk membuat dan menginisialisasi data pelajaran baru, serta prosedur tampil_pelajaran() yang berfungsi untuk menampilkan isi data pelajaran. File ini menggunakan directive #ifndef, #define, dan #endif sebagai header guard untuk mencegah pendefinisian ganda saat file di-include ke beberapa file lain dalam satu program.

### 3. program file pelajaran.cpp

```C++
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


```
Fungsi program ini untuk mengimplementasikan Abstract Data Type (ADT) pelajaran yang telah dideklarasikan sebelumnya di file header pelajaran.h. Program ini menggunakan fungsi, prosedur, dan struct untuk memproses serta menampilkan data pelajaran. Fungsi create_pelajaran() berfungsi membuat sebuah objek pelajaran baru dengan mengisi atribut namaMapel dan kodeMapel berdasarkan nilai parameter yang diterima, kemudian mengembalikan objek tersebut. Sedangkan prosedur tampil_pelajaran() digunakan untuk menampilkan data pelajaran ke layar dengan format yang rapi. Program ini menunjukkan penerapan konsep pemrograman modular, di mana implementasi fungsi dan prosedur dipisahkan dari file header agar kode lebih terstruktur dan mudah dikelola.

### 4. program file main.cpp

```C++
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
Fungsi program ini untuk menampilkan data pelajaran menggunakan Abstract Data Type (ADT) yang telah dibuat sebelumnya. Program ini menggunakan fungsi utama (main), variabel string, dan pemanggilan fungsi dari file header eksternal. Pertama, program mendeklarasikan dua variabel yaitu namapel dan kodepel untuk menyimpan nama serta kode mata pelajaran. Nilai-nilai tersebut kemudian dikirim ke fungsi create_pelajaran() untuk membuat objek pelajaran. Setelah objek terbentuk, prosedur tampil_pelajaran() dipanggil untuk menampilkan informasi nama dan kode pelajaran ke layar. Program ini menerapkan konsep modularitas, karena fungsi pembuatan dan penampilan data dipisahkan dalam file berbeda agar lebih rapi dan mudah digunakan kembali.

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
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan3_modul3/ss-ungguided1.png)




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

### file nya saya pisah jadi 3
### 1. file pelajaran.h

```C++

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


```

### 2. file pelajaran.cpp

```C++
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


```


### 3. file main.cpp

```C++
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
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan3_modul3/ss-ungguided2.png)




penjelasan unguided 2

Fungsi keseluruhan dari tiga program ini adalah untuk penerapan Abstract Data Type (ADT) dengan pendekatan modular menggunakan tiga file terpisah, yaitu pelajaran.h, pelajaran.cpp, dan main.cpp. File pelajaran.h berfungsi sebagai header file yang mendefinisikan struktur data pelajaran berisi dua atribut (namaMapel dan kodeMapel), serta deklarasi fungsi create_pelajaran() dan prosedur tampil_pelajaran(). File pelajaran.cpp berisi implementasi fungsi dan prosedur tersebut — create_pelajaran() digunakan untuk membuat objek pelajaran baru berdasarkan input parameter, sedangkan tampil_pelajaran() menampilkan isi data pelajaran ke layar. Sementara itu, file main.cpp berperan sebagai program utama yang menginisialisasi data pelajaran (“Struktur Data”, “STD”), memanggil fungsi create_pelajaran() untuk membentuk objek, lalu menampilkan hasilnya dengan tampil_pelajaran(). Secara keseluruhan, program ini menggunakan struct, fungsi, prosedur, dan konsep modularitas, yang membuat kode lebih terstruktur, mudah dibaca, serta mendukung prinsip pemrograman berorientasi abstraksi data.

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
![Screenshot Output Unguided 3_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan3_modul3/ss-ungguided3.png)



penjelasan unguided 3

Fungsi program ini adalah untuk menampilkan dan menukar elemen-elemen dalam dua array dua dimensi (matriks) serta mendemonstrasikan pertukaran nilai menggunakan pointer. Program ini menggunakan array 2 dimensi, fungsi, perulangan for, dan pointer. Dua matriks A dan B berukuran 3×3 diinisialisasi dengan nilai berbeda, kemudian fungsi tampilArray() digunakan untuk menampilkan isi masing-masing matriks. Fungsi tukarPosisi() berfungsi menukar elemen pada posisi tertentu antara kedua matriks menggunakan variabel sementara (temp). Selain itu, fungsi tukarPointer() digunakan untuk menukar nilai dua variabel melalui alamat memori menggunakan pointer. Dengan kombinasi elemen-elemen tersebut, program ini menunjukkan cara kerja array dua dimensi, perulangan bersarang, dan manipulasi data melalui pointer.

## Kesimpulan
Kesimpulan dari modul 3 ini adalah bahwa penerapan Abstract Data Type (ADT) memungkinkan pemisahan antara definisi data dan cara pengelolaannya melalui penggunaan struct, fungsi, dan prosedur secara modular. Melalui latihan guided dan unguided, mahasiswa dapat memahami bagaimana ADT diterapkan untuk menyimpan dan memproses data seperti mahasiswa, pelajaran, serta operasi pertukaran nilai pada array dan pointer. Dengan memanfaatkan konsep modularitas, array, perulangan, dan pointer, program menjadi lebih terstruktur, efisien, dan mudah dikelola, sekaligus menunjukkan pentingnya abstraksi data dalam membangun program yang rapi dan mudah dikembangkan.

## Referensi
[1] Schmidt, D. C., ADTs, D. O. U., & ADTs, B. I. C++ Support for Abstract Data Types. 
<br>[2] Khoerul, A. (2023). Pengantar Struktur Data Full.

