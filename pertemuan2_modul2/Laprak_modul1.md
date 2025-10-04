# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
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
#include <iostream>

using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << ":";
        cin >> arr[i];
    }   
    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke-" << j << ":" << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Fungsi program ini adalah untuk mendemonstrasikan pengisian dan pembacaan data ke dalam array satu dimensi. Program ini mendeklarasikan sebuah array integer berukuran 5 elemen. Perulangan for digunakan untuk meminta pengguna memasukkan nilai ke setiap elemen array secara berurutan, dari indeks 0 hingga 4. Setelah itu, perulangan while digunakan untuk membaca dan menampilkan kembali nilai yang tersimpan di dalam setiap elemen array tersebut.

### 2. Program Operasi Matriks 2x2

```C++
#include <iostream>

using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Tampilkan hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    //perkalian matriks
    for (int i = 0; i < 2; i++) {                           //perulangan baris
        for (int j = 0; j < 2; j++) {                       //perulangan kolom
            for (int k = 0; k < 2; k++) {                   //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Tampilkan hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
}
```
Fungsi program ini adalah untuk mendemonstrasikan operasi penjumlahan dan perkalian pada dua Matriks 2x2. Program ini menginisialisasi dua array dua dimensi (arrA dan arrB) yang bertindak sebagai matriks. Program menggunakan fungsi void bernama tampilkanHasil untuk mencetak array hasil dengan rapi. Operasi penjumlahan dilakukan dengan dua perulangan bersarang, menjumlahkan elemen pada indeks yang sama. Sementara itu, operasi perkalian menggunakan tiga perulangan bersarang (untuk baris, kolom, dan perkalian elemen) untuk menghitung hasil kali skalar baris arrA dengan kolom arrBS.

### 3. Program Pencarian Nilai Maksimum dan Operasi Aritmatika Array

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl;
}
int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}

```
Fungsi program ini adalah untuk menganalisis array satu dimensi yang nilainya diinputkan oleh pengguna, dengan menggunakan dua fungsi terpisah. Program ini mendeklarasikan array berukuran 5 dan menggunakan perulangan for untuk meminta pengguna memasukkan nilai ke dalamnya. Tugas utama program dipecah menjadi dua modul: Fungsi cariMAX yang digunakan untuk menemukan dan mengembalikan nilai terbesar (maksimum) dalam array tersebut, dan Prosedur operasiAritmatika yang menghitung dan mencetak total penjumlahan serta total perkalian dari semua elemen array. Secara keseluruhan, program ini menunjukkan modularitas dengan memisahkan logika pencarian dan perhitungan array ke dalam unit-unit fungsional.

### 4. Program Pointer dan Pertukaran Nilai Variabel

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (adress of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Fungsi program C++ ini adalah untuk mendemonstrasikan konsep pointer dan mekanisme Call by Pointer. Program mendeklarasikan variabel pointer ptr dan menggunakannya untuk menyimpan alamat memori (&a) variabel a. Puncak fungsinya adalah prosedur tukar, yang menerima alamat &a dan &b sebagai parameter (Call by Pointer) dan berhasil menukar nilai asli dari a dan b di luar fungsi main().

### 5. Program Demonstrasi Reference dan Swap

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (alias a): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}
```
Fungsi program C++ ini adalah untuk mendemonstrasikan konsep reference (alias) dan mekanisme Call by Reference. Program mendeklarasikan variabel a dan b, kemudian menciptakan sebuah referensi (ref) yang bertindak sebagai alias untuk variabel a (int& ref = a). Setiap modifikasi yang dilakukan pada ref akan secara langsung mengubah nilai variabel asli a. Puncak fungsinya adalah prosedur tukar, yang menggunakan mekanisme Call by Reference untuk berhasil menukar nilai asli dari a dan b di luar fungsi main().

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>

using namespace std;

const int N = 3; 

void penjumlahan(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pengurangan(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalian(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void tampilkan_matriks(int M[N][N], const char* nama) {
    cout << "matriks " << nama << " (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
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

    int C[N][N];

    tampilkan_matriks(A, "A");
    tampilkan_matriks(B, "B");

    penjumlahan(A, B, C);
    tampilkan_matriks(C, "hasil penjumlahan (A + B)");

    pengurangan(A, B, C);
    tampilkan_matriks(C, "hasil pengurangan (A - B)");

    perkalian(A, B, C);
    tampilkan_matriks(C, "hasil perkalian (A x B)");

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided11.png)

penjelasan unguided 1 

Program ini berfungsi untuk melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua Matriks 3x3. Program ini menggunakan Array Dua Dimensi dan memecah setiap operasi matematika menjadi fungsi terpisah (penjumlahan, pengurangan, perkalian, dan tampilkan_matriks). Setiap fungsi operasi matriks menggunakan perulangan bersarang (nested loops) untuk mengolah elemen-elemennya. Secara khusus, fungsi perkalian menggunakan tiga loop bersarang, sesuai dengan aturan perkalian matriks, di mana setiap elemen hasil adalah penjumlahan dari hasil kali elemen baris Matriks A dengan kolom Matriks B. 

### 2. Soal unguided 2

Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
#include <iostream>

using namespace std;

void tukar_pointer(int *A, int *B, int *C) {
    int temp;
    temp = *A;
    *A = *C;
    *C = *B;
    *B = temp;
}

void tukar_referensi(int &X, int &Y, int &Z) {
    int temp;
    temp = X;
    X = Z;
    Z = Y;
    Y = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << " demo call by pointer " << endl;
    cout << "Sebelum ditukar: a=" << a << ", b=" << b << ", c=" << c << endl;
    
    tukar_pointer(&a, &b, &c); 
    
    cout << "Setelah ditukar: a=" << a << ", b=" << b << ", c=" << c << endl;
    
  

    int x = 11, y = 22, z = 33;

    cout << " demo call by reference " << endl;
    cout << "Sebelum ditukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    
    tukar_referensi(x, y, z);
    
    cout << "Setelah ditukar: x=" << x << ", y=" << y << ", z=" << z << endl;
    
    return 0;
}
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

Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata

```C++
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

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan2_modul2/ss-ungguided33.png)



penjelasan unguided 3

Program ini berfungsi sebagai Menu Interaktif untuk menganalisis statistik dasar dari sebuah array satu dimensi. Program ini menggunakan struktur switch-case untuk memproses pilihan pengguna.

Logika utamanya dipecah menjadi beberapa fungsi dan prosedur yang terpisah:
 1.Fungsi cariminimum() dan carimaksimum(): Keduanya menggunakan perulangan for untuk membandingkan setiap elemen array dan mengembalikan nilai ekstrem (fungsi dengan return value).
 2.Prosedur hitungRataRata(): Menggunakan perulangan for untuk menjumlahkan semua elemen dan menghitung rata-rata, lalu menampilkan hasilnya (prosedur void tanpa return value).
 3.Prosedur tampilkanarray(): Berfungsi untuk mencetak semua isi elemen array.

Program utama (main) terus menampilkan menu dan menjalankan fungsi yang dipilih melalui perulangan do-while hingga pengguna memilih opsi 5 (Keluar)..

## Kesimpulan

Praktikum Modul 2 memperdalam pemahaman mahasiswa mengenai penggunaan array, pointer, reference, serta perulangan dalam C++. Melalui latihan guided, mahasiswa berlatih mengimplementasikan operasi dasar seperti manipulasi array, operasi matriks, dan variasi loop. Pada latihan unguided, mahasiswa mengembangkan logika mandiri untuk membuat program operasi matriks 3x3, pertukaran nilai dengan pointer dan reference, serta analisis statistik array menggunakan menu interaktif. Praktikum ini melatih kemampuan problem solving sekaligus membangun dasar penting untuk mempelajari algoritma dan struktur data lanjutan.

## Referensi
[1] Pratama, H. J., Ali, E. P., Nurvia, M., & Harahap, E. (2021). Aplikasi penjumlahan dan perkalian matriks pada microsoft excel. Matematika: Jurnal Teori dan Terapan Matematika, 20(1), 17-22. 
<br>[2] Nuraini, R. (2015). Desain algorithma operasi perkalian matriks menggunakan metode flowchart. Jurnal teknik komputer, 1(1), 144-151.
<br>[3] Ma’arif, A. (2021). Dasar pemrograman bahasa C++ [Buku ajar]. Universitas Ahmad Dahlan.
<br>[4] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

