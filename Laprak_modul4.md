# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST(BAGIAN PERTAMA)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>

## Dasar Teori

### A.Abstract Data Type (ADT) dan Struktur Data
Abstract Data Type (ADT) atau tipe data abstrak merupakan konsep dalam pemrograman yang mendefinisikan sekumpulan operasi yang dapat dilakukan pada suatu tipe data tanpa harus mengetahui bagaimana data tersebut disimpan atau diimplementasikan. ADT berfungsi sebagai bentuk abstraksi untuk menyembunyikan detail implementasi dan hanya menampilkan antarmuka yang digunakan oleh pengguna program. Dengan pendekatan ini, pemrogram dapat memisahkan antara cara penggunaan data dan cara penyimpanan data secara internal.[1]

### B.Singly Linked List (SLL)
Singly Linked List adalah struktur data dinamis yang terdiri dari elemen-elemen (disebut node) yang saling terhubung. Berbeda dengan array yang memiliki ukuran statis dan akses cepat via indeks , SLL lebih fleksibel dalam penyisipan dan penghapusan data karena tidak memerlukan pergeseran elemen. Secara intuitif, doubly linked list (yang memiliki dua arah) lebih efisien daripada singly linked list. Hal ini karena SLL pada dasarnya bersifat satu arah; tidak ada cara untuk menggerakkan pointer ke posisi sebelumnya (mundur), kecuali dengan menyimpan alamat node tersebut di variabel lain.[2]

### C.Karakteristik Operasi List
Setiap struktur data memiliki keunggulan performa yang berbeda. Array unggul dalam akses data langsung (jika indeks diketahui), yang memiliki kompleksitas waktu $O(1)$99999999. Sebaliknya, SLL memerlukan penelusuran sekuensial dari node first untuk mencari data, sehingga operasi pencariannya memiliki kompleksitas $O(n)$10101010. Namun, SLL lebih unggul dalam fleksibilitas; operasi seperti penambahan atau penghapusan elemen di awal list (seperti insertFirst dan delFirst) dapat dilakukan dalam waktu konstan $O(1)$11111111. Karena itu, SLL lebih cocok untuk data yang ukurannya dinamis atau sering berubah.[2]

## Guided 

##### 1. guided 1 

### 1. File list.h 
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
dataMahasiswa isidata;
address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist &List);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);


#endif
```


### 2. File list.cpp 

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist &List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```


### 3. File main.cpp 

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Fungsi keseluruhan dari ketiga file ini adalah untuk implementasi Abstract Data Type (ADT) berupa single linked list secara modular untuk mengelola data mahasiswa. Program ini terbagi menjadi tiga file: list.h, list.cpp, dan main.cpp. File list.h berperan sebagai header yang mendefinisikan semua struktur data yang dibutuhkan, seperti mahasiswa untuk menyimpan data dan node sebagai elemen list, serta mendeklarasikan prototipe dari semua fungsi dan prosedur yang dapat dioperasikan pada list, misalnya insertFirst() dan printList(). Selanjutnya, file list.cpp berisi implementasi atau definisi detail dari setiap fungsi yang telah dideklarasikan di list.h, menjelaskan bagaimana setiap operasi—seperti alokasi memori, penyisipan node di awal, tengah, dan akhir—sebenarnya bekerja secara logis. Sementara itu, main.cpp berfungsi sebagai program utama atau driver yang menggunakan ADT tersebut. Di dalam file ini, sebuah list kosong dibuat, lima data mahasiswa dialokasikan ke dalam node-node terpisah, lalu dimasukkan ke dalam list menggunakan berbagai fungsi insert untuk membentuk sebuah struktur data yang terhubung. Pada akhirnya, program memanggil printList() untuk menampilkan isi akhir dari list yang telah dimanipulasi. Secara konsep, kode ini secara efektif memisahkan antara antarmuka (deklarasi di .h) dengan implementasi (definisi di .cpp), yang merupakan inti dari prinsip modularitas dan abstraksi dalam pemrograman.

### 2. guided 2

### 1.file list.h

```C++

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;


struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};


bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist &List); 

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);


#endif

```

### 2.file list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){ 
            List.first = Nil; 
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    address nodeHapus;
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist &List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}


```


### 3.file main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
}


```
Fungsi keseluruhan dari ketiga file ini adalah untuk implementasi Abstract Data Type (ADT) berupa single linked list secara modular untuk mengelola data mahasiswa. Program ini terbagi menjadi tiga file: list.h, list.cpp, dan main.cpp. File list.h berfungsi sebagai header yang mendefinisikan seluruh struktur data dasar yang dibutuhkan—seperti mahasiswa untuk menyimpan data dan node sebagai elemen list—serta mendeklarasikan prototipe dari semua fungsi dan prosedur yang dapat dioperasikan pada list, mulai dari pembuatan, penyisipan, penghapusan, hingga pencetakan. Selanjutnya, file list.cpp berisi implementasi atau definisi detail dari setiap fungsi yang telah dijanjikan di list.h, menjelaskan bagaimana setiap operasi—seperti alokasi memori, penyisipan node, penghapusan elemen, hingga penghitungan jumlah node—sebenarnya bekerja secara logis. Sementara itu, main.cpp bertindak sebagai program utama atau driver yang mendemonstrasikan penggunaan ADT tersebut secara praktis. Di dalamnya, sebuah list diinisialisasi, diisi dengan data mahasiswa melalui berbagai fungsi insert, kemudian ditampilkan. Program kemudian melanjutkan dengan menguji operasi penghapusan menggunakan delFirst, delLast, dan delAfter, sebelum akhirnya menghapus keseluruhan list untuk menunjukkan manajemen memori yang lengkap. Secara konseptual, program ini secara efektif memisahkan antara antarmuka (deklarasi di .h) dengan implementasi (definisi di .cpp), yang merupakan inti dari prinsip abstraksi dan modularitas dalam pemrograman, sehingga menghasilkan kode yang terstruktur, dapat digunakan kembali (reusable), dan mudah untuk dikelola.

## Unguided 

### 1. Soal Unguided 1

Buatlah file header Singlylist.h yang berisi definisi struktur data dan prototipe fungsi/prosedur berikut:

Definisi Tipe:
Type infotype : int
Type address : pointer to ElmList
Type ElmList < info : infotype, next : address >
Type List < First : address >

Prototipe Fungsi dan Prosedur:

procedure CreateList(input/output L : List)
function alokasi(x : infotype) -> address
procedure dealokasi(input/output P : address)
procedure printInfo(input L : List)
procedure insertFirst(input/output L : List, input P : address)

2. File Implementasi (Singlylist.cpp)

Buatlah file implementasi Singlylist.cpp yang berisi definisi (isi) dari semua prosedur dan fungsi yang telah dideklarasikan di Singlylist.h.

3. File Utama (main.cpp)

Buatlah program utama main.cpp dengan implementasi sebagai berikut untuk menguji ADT yang telah dibuat:

C++

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
Program ini diharapkan menghasilkan linked list dengan urutan elemen 9 -> 12 -> 8 -> 0 -> 2.

## 1. file singlylist.h
```C++
#ifndef LINGLYLIST_H
#define LINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct ElmList *address;

struct ElmList {
  infotype info;
  address next;
};

struct list {
    address first;
};

void createList (list &l);
address alokasi (infotype x);
void  dealokasi (address p);
void printInfo(list L);
void insertFirst (list &L,address p);

#endif


```

## 2. file singlylist.cpp
```C++
#include "singlylist.h"
using namespace std;

void createList(list &L) {
 L.first = Nil;
}

address alokasi (infotype x) {
   address p = new ElmList;
   p->info =x;
   p->next=Nil;
   return p;
}

void dealokasi(address p){
   delete p;
}

void printInfo(list L) {
     address p = L.first;
     while (p != Nil) {
        cout <<  p->info << " ";
        p = p->next;
     }
     cout << endl;
}

void insertFirst(list &L, address p){
 p ->next =L.first;
 L.first = p;
}



```
## 3. file main.cpp

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
 list L;
 address p1,p2,p3,p4,p5 = Nil;
 createList(L);

 p1 = alokasi(2);
 insertFirst(L,p1);

 p2 = alokasi(0);
 insertFirst(L,p2);

 p3 = alokasi(8);
 insertFirst(L,p3);

 p4 = alokasi(12);
 insertFirst(L,p4);

 p5 = alokasi(9);
 insertFirst(L,p5);

printInfo (L);
return 0;

}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan4_modul4/ss-ungguided1.png)


penjelasan unguided 1 

Program ini bertujuan untuk menerapkan struktur data singly linked list menggunakan pendekatan modular yang membagi kode ke dalam tiga file terpisah. File singlylist.h bertindak sebagai header yang mendefinisikan semua struktur data, seperti ElmList (node) dan list, serta mendaftarkan semua prototipe fungsi yang akan digunakan. File singlylist.cpp berisi implementasi atau logika dari setiap fungsi tersebut, menjelaskan cara kerja createList untuk inisialisasi, alokasi untuk memesan memori, dealokasi untuk menghapus memori, printInfo untuk mencetak list, dan insertFirst untuk menambah data di awal list. Terakhir, file main.cpp adalah program utama yang menggunakan fungsi-fungsi tersebut. Di sini, sebuah list kosong dibuat, lalu lima node (berisi 2, 0, 8, 12, dan 9) dimasukkan satu per satu ke awal list. Karena selalu menggunakan insertFirst, data terakhir yang dimasukkan (9) akan menjadi yang pertama, sehingga pemanggilan printInfo akan menampilkan hasil akhir "9 12 8 0 2".

### 2. Soal unguided 2

Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst,node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tempilkan jumlah node yang terpisah menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList();


### 1. file singlylist.h

```C++

#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil nullptr

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList{
    infotype info;
    address next;
};

struct list {
     address first;
};

void createList(list &L);
address alokasi(infotype x);
void dealokasi(address p);
void printInfo(list L);
void insertFirst(list &L, address p);

void delFirst(list &L);
void delLast(list &L);
void delAfter(list &L, address Prec); 
int nbList(list L);
void deleteList(list &L);
#endif


```

### 2. file singlylist.cpp

```C++
#include "singlylist.h"
using namespace std;

void createList(list &L) {
 L.first = Nil;
}

address alokasi (infotype x) {
   address p = new ElmList;
   p->info =x;
   p->next=Nil;
   return p;
}

void dealokasi(address p){
   delete p;
}

void printInfo(list L) {
     address p = L.first;
     while (p != Nil) {
        cout <<  p->info << " ";
        p = p->next;
     }
     cout << endl;
}

void insertFirst(list &L, address p){
 p ->next =L.first;
 L.first = p;
}


void delFirst(list &L) {
    if (L.first != Nil) {
        address p = L.first;
        L.first = p->next;
        dealokasi(p);
    }
}


void delLast(list &L) {
    if (L.first == Nil) {
     
        return;
    }

    address p = L.first;
    address prev = Nil;

    if (p->next == Nil) {
       
        L.first = Nil;
        dealokasi(p);
    } else {
        while (p->next != Nil) {
            prev = p;
            p = p->next;
        }
        prev->next = Nil;
        dealokasi(p);
    }
}


void delAfter(list &L, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address p = Prec->next; 
        Prec->next = p->next;  
        dealokasi(p);
    }
}


int nbList(list L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}


void deleteList(list &L) {
    address p = L.first;
    address temp;

    while (p != Nil) {
        temp = p;
        p = p->next;
        dealokasi(temp);
    }
    L.first = Nil;

 
    cout << "- List Berhasil Terhapus -" << endl;
}



```


### 3. file main.cpp

```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    list L;
    address p1, p2, p3, p4, p5;
    createList(L);

    p1 = alokasi(2);
    insertFirst(L, p1);

    p2 = alokasi(0);
    insertFirst(L, p2);

    p3 = alokasi(8);
    insertFirst(L, p3);

    p4 = alokasi(12);
    insertFirst(L, p4);

    p5 = alokasi(9);
    insertFirst(L, p5);

   
    delFirst(L);
 
    delLast(L);
    delAfter(L, p4);
   
    
  
    printInfo(L);

   
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

   
    deleteList(L);
   cout << "Jumlah node : " << nbList(L) << endl;
}


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan4_modul4/ss-ungguided2.png)


penjelasan unguided 2

Program ini merupakan lanjutan dari soal pertama Penambahan ini terlihat di file singlylist.h dengan mendeklarasikan prototipe untuk prosedur-prosedur penghapusan (delFirst, delLast, delAfter) serta fungsi utilitas (nbList untuk menghitung node dan deleteList untuk mengosongkan list). Sesuai dengan itu, file singlylist.cpp juga diperbarui dengan implementasi untuk semua fungsi baru tersebut, menjelaskan cara kerja setiap operasi hapus. Terakhir, file main.cpp bertindak sebagai program penguji yang pertama membuat list awal (dari soal 1), kemudian langsung mendemonstrasikan fungsi-fungsi baru dengan menghapus node 9, 2, dan 8. Sebagai hasil akhir, program mencetak isi list yang tersisa (12 0), menampilkan jumlah node (2), dan memanggil deleteList untuk mengosongkan list sepenuhnya.


## Kesimpulan
Kesimpulan dari modul 3 ini adalah bahwa penerapan Abstract Data Type (ADT) memungkinkan pemisahan antara definisi data dan cara pengelolaannya melalui penggunaan struct, fungsi, dan prosedur secara modular. Melalui latihan guided dan unguided, mahasiswa dapat memahami bagaimana ADT diterapkan untuk menyimpan dan memproses data seperti mahasiswa, pelajaran, serta operasi pertukaran nilai pada array dan pointer. Dengan memanfaatkan konsep modularitas, array, perulangan, dan pointer, program menjadi lebih terstruktur, efisien, dan mudah dikelola, sekaligus menunjukkan pentingnya abstraksi data dalam membangun program yang rapi dan mudah dikembangkan.

## Referensi
[1] Schmidt, D. C., ADTs, D. O. U., & ADTs, B. I. C++ Support for Abstract Data Types. 
<br>[2] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Jurnal Penelitian Nusantara, 1(6), 871-877.
<br>[3] Ben-Amram, A. M., & Petersen, H. (1999). Backing up in Singly Linked Lists. Proceedings of the thirty-first annual ACM symposium on Theory of computing (STOC '99), 780–786.


