# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST(BAGIAN KEDUA)</h1>
<p align="center">Ma'ruf Sarifudin - 103112400128</p>


## Dasar Teor

### A. Singly Linked List (SLL)

Singly Linked List (SLL) merupakan salah satu bentuk struktur data dinamis yang banyak digunakan dalam pemrograman karena kemampuannya dalam menyimpan dan mengelola data secara fleksibel. Berbeda dengan array yang memiliki ukuran tetap dan memori yang dialokasikan secara berurutan, linked list memungkinkan penambahan atau penghapusan elemen tanpa perlu menggeser posisi elemen lain di dalam memori. Setiap elemen di dalam linked list disebut node, dan setiap node terdiri dari dua bagian utama, yaitu data (yang menyimpan nilai atau informasi) dan pointer (yang menunjuk ke node berikutnya). Node pertama dalam list disebut head, sedangkan node terakhir memiliki pointer bernilai NULL karena tidak ada elemen setelahnya.
Kelebihan utama dari SLL adalah kemampuannya untuk melakukan operasi penyisipan (insert) dan penghapusan (delete) dengan lebih efisien dibandingkan array, terutama ketika posisi node yang ingin dimanipulasi sudah diketahui. Namun, kekurangannya terletak pada proses pencarian data — untuk menemukan node pada posisi tertentu, program harus menelusuri list dari awal hingga node yang dimaksud. Hal ini menyebabkan waktu akses bersifat linear (O(n)), sehingga tidak secepat struktur seperti array yang mendukung akses langsung (direct access). Dalam implementasi modern, SLL sering digunakan pada sistem yang membutuhkan efisiensi memori dan fleksibilitas tinggi, seperti sistem antrian dinamis, tabel hash, serta manajemen memori pada sistem operasi.[1]


### B.Operasi Dasar pada Linked List
Linked list memiliki berbagai operasi dasar yang menjadi fondasi dalam manipulasi datanya. Pertama, terdapat operasi penyisipan (insertion) yang terdiri atas tiga jenis: insertFirst, insertAfter, dan insertLast. Fungsi insertFirst digunakan untuk menambahkan node baru di awal list, menjadikannya sebagai node pertama. Fungsi insertAfter digunakan untuk menyisipkan node setelah node tertentu yang sudah diketahui, sedangkan insertLast digunakan untuk menambahkan node baru di akhir list. Ketiga fungsi ini menunjukkan bahwa linked list dapat berkembang secara dinamis tanpa batas ukuran tertentu.

Selanjutnya, terdapat operasi penghapusan (deletion) seperti delFirst, delAfter, dan delLast. Operasi delFirst digunakan untuk menghapus node pertama, delAfter untuk menghapus node setelah node tertentu, dan delLast untuk menghapus node terakhir dari list. Keuntungan utama operasi ini adalah efisiensinya, karena penghapusan node dapat dilakukan tanpa perlu memindahkan elemen lain seperti pada array, selama pointer node sebelumnya sudah diketahui.

Selain itu, terdapat operasi pencarian (search) yang berfungsi menemukan node berdasarkan kriteria tertentu. Fungsi searchByData mencari node berdasarkan nilai data yang disimpan, searchByAddress mencari berdasarkan alamat memori node, dan searchByRange digunakan untuk mencari node dengan nilai tertentu (misalnya semua node yang memiliki nilai lebih besar dari angka tertentu). Karena linked list tidak mendukung akses acak, maka seluruh proses pencarian dilakukan secara berurutan dari node pertama hingga terakhir, sehingga kompleksitas waktunya adalah O(n).

Terakhir, terdapat operasi update, yang digunakan untuk memperbarui isi dari node tertentu tanpa mengubah struktur list-nya. Operasi ini menunjukkan bahwa data di dalam linked list bersifat dinamis dan dapat dimodifikasi sewaktu-waktu sesuai kebutuhan program. Kombinasi dari operasi insert, delete, search, dan update menjadikan linked list sebagai salah satu struktur data dasar yang sangat penting dalam dunia pemrograman dan algoritma.[2]


### C.Manajemen Memori Dinamis pada Linked List

Salah satu karakteristik penting dari linked list adalah penggunaan memori dinamis, terutama ketika diimplementasikan dalam bahasa seperti C atau C++. Dalam sistem ini, setiap node tidak disimpan secara berurutan di dalam memori, melainkan dialokasikan secara terpisah menggunakan fungsi alokasi dinamis (seperti new pada C++ atau malloc pada C). Proses ini memungkinkan program untuk menambahkan node baru kapan pun dibutuhkan tanpa perlu menentukan ukuran awal list. Setelah node tidak lagi digunakan, memori yang dialokasikan harus dibebaskan kembali menggunakan fungsi dealokasi (seperti delete atau free) agar tidak terjadi memory leak atau kebocoran memori.

Manajemen memori yang baik sangat penting dalam implementasi linked list karena setiap node bergantung pada pointer untuk menjaga keterhubungan antar-node. Jika ada kesalahan pada penanganan pointer (misalnya pointer yang tidak dihapus atau salah arah), maka dapat terjadi dangling pointer atau akses ke memori ilegal, yang dapat menyebabkan program error atau crash. Oleh karena itu, setiap operasi seperti alokasi, dealokasi, insert, dan delete harus diatur secara hati-hati agar hubungan antar-node tetap konsisten.
Dengan demikian, konsep manajemen memori dinamis pada linked list tidak hanya memperlihatkan fleksibilitas struktur data ini, tetapi juga menuntut pemahaman mendalam tentang bagaimana komputer mengelola memori pada tingkat rendah — sebuah konsep penting yang menjadi dasar dalam pengembangan algoritma dan sistem perangkat lunak modern.[3]


## Guided 

##### 1. guided 1 

### 1. File listBuah.h 
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```


### 2. File listBuah.cpp 

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


```

### 3. File main.cpp 

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas adalah contoh penerapan struktur data Linked List yang digunakan untuk menyimpan dan mengelola data buah-buahan. Program ini terdiri dari tiga bagian utama: file listBuah.h yang berisi deklarasi struktur dan fungsi, file listBuah.cpp yang berisi implementasi fungsi-fungsinya, dan file main.cpp yang menjadi tempat menjalankan seluruh proses program.

Pada file listBuah.h, dibuat beberapa struktur penting. Pertama ada struct buah yang menyimpan data nama buah, jumlah, dan harga. Lalu ada struct node yang berfungsi sebagai wadah tiap elemen dalam linked list, di mana setiap node berisi data buah (isidata) dan penunjuk (next) ke node berikutnya. Kemudian ada struct linkedlist yang hanya berisi satu penunjuk yaitu first sebagai penanda node pertama dalam list. Selain itu, dalam file ini juga dideklarasikan semua fungsi yang akan digunakan seperti untuk menambah, menghapus, memperbarui, dan mencari data dalam list.

File listBuah.cpp berisi implementasi dari semua fungsi tersebut. Fungsi isEmpty digunakan untuk memeriksa apakah list kosong atau tidak, sementara createList membuat list baru dengan nilai awal kosong. Fungsi alokasi digunakan untuk membuat node baru berisi data buah, sedangkan dealokasi digunakan untuk menghapus node dan mengembalikan memori. Ada beberapa fungsi untuk menambah data ke dalam list: insertFirst untuk menambah di awal, insertLast untuk menambah di akhir, dan insertAfter untuk menambah setelah node tertentu. Begitu juga untuk menghapus data, ada delFirst, delLast, dan delAfter yang masing-masing menghapus node dari posisi berbeda. Fungsi printList digunakan untuk menampilkan semua isi list, sedangkan nbList menghitung jumlah node yang ada. Fungsi deleteList berguna untuk menghapus seluruh isi list sekaligus.

Selain itu, ada bagian update (materi modul 5 bagian 1) yang terdiri dari tiga fungsi: updateFirst, updateLast, dan updateAfter. Fungsi-fungsi ini digunakan untuk memperbarui data buah pada node pertama, node terakhir, atau node setelah posisi tertentu. Program juga memiliki bagian searching (modul 5 bagian 2), yaitu FindNodeByData untuk mencari berdasarkan nama buah, FindNodeByAddress untuk mencari berdasarkan alamat memori node, dan FindNodeByRange untuk mencari buah dengan harga dalam rentang tertentu.

Terakhir, pada file main.cpp, program dijalankan mulai dari membuat list kosong dengan createList. Lalu dibuat beberapa node buah seperti Jeruk, Apel, Pir, Semangka, dan Durian menggunakan fungsi alokasi, kemudian dimasukkan ke list menggunakan kombinasi insertFirst, insertLast, dan insertAfter. Setelah itu, seluruh data list ditampilkan. Program kemudian melakukan update terhadap data tertentu menggunakan fungsi updateFirst, updateLast, dan updateAfter, lalu menampilkan hasilnya. Selanjutnya dilakukan pencarian data menggunakan tiga metode pencarian yang berbeda. Kemudian dilakukan penghapusan node dari awal, akhir, dan setelah node tertentu, dan ditampilkan kembali hasilnya. Pada akhir program, seluruh isi list dihapus menggunakan deleteList, sehingga list kembali kosong.


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

## 1. file ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct list {
    address first;
};

void createList(list &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(const list &L);
void insertFirst(list &L, address nodeBaru);
void insertAfter(list &L, address nodeBaru, address nodePrev);
void insertLast(list &L, address nodeBaru);
int nbList(const list &L);
void delAfter(list &L, address &nodeHapus, address nodePrev);
bool isEmpty(list L);

void updateFirst(list L);
void updateAfter(list L, address nodePrev);
void updateLast(list L);

#endif

```

## 2. file ListAngka.cpp
```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

void createList(list &L) {
    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    if (nodeBaru != Nil) {
        nodeBaru->angka = x;
        nodeBaru->next = Nil;
    }
    return nodeBaru;
}

void dealokasi(address &node) {
    delete node;
    node = Nil;
}

void printList(const list &L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address p = L.first;
        while (p != Nil) {
            cout << p->angka << " - ";
            p = p->next;
        }
        cout << endl;
    }
}

void insertFirst(list &L, address nodeBaru) {
    if (nodeBaru != Nil) {
       nodeBaru->next = L.first;
       L.first = nodeBaru;
    }
}

void insertAfter(list &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil && nodeBaru != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else if (nodePrev == Nil) {
        cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
    }
}

void insertLast(list &L, address nodeBaru) {
    if (nodeBaru == Nil) return;

    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address p = L.first;
        while (p->next != Nil) {
            p = p->next;
        }
        p->next = nodeBaru;
    }
}

int nbList(const list &L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(list &L, address &nodeHapus, address nodePrev) {
    if (L.first == Nil) {
        nodeHapus = Nil;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
    } else {
        nodeHapus = Nil;
    }
}

bool isEmpty(list L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void updateFirst(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void  updateLast(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Angka : ";
        cin >> nodeBantu->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(list L, address nodePrev) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
            cout << "Angka : ";
            cin >> nodeBantu->angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}


```
## 3. file main.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    list L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    address nodeHapus = Nil;

    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    delAfter(L, nodeHapus, nodeC);
    printList(L);
    cout << "jumlah node : " << nbList(L) << endl;
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);
    

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(L);
    cout << endl;
    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan5_modul5/ss-ungguided1.png)


penjelasan unguided 1 

Program di atas adalah contoh penggunaan linked list untuk menyimpan sekumpulan angka secara dinamis. Program ini dibagi menjadi tiga bagian utama, yaitu file ListAngka.h sebagai kerangka atau rancangan fungsi dan struktur data, file ListAngka.cpp yang berisi isi atau cara kerja setiap fungsi, dan file main.cpp yang berfungsi sebagai tempat menjalankan program utama.

Pada file ListAngka.h, pertama-tama dibuat struktur dasar data yang dibutuhkan. Ada struct node yang berisi satu data angka dan satu pointer bernama next untuk menunjuk ke node berikutnya. Lalu ada struct list yang hanya berisi satu pointer first, yaitu penunjuk ke node pertama dalam daftar. File ini juga berisi daftar semua fungsi yang akan digunakan, seperti membuat list, menambah node (insert), menghapus node (delete), memperbarui data (update), serta menampilkan isi list. Tujuannya agar program menjadi lebih terstruktur dan mudah dikelola.

Selanjutnya, pada file ListAngka.cpp, seluruh fungsi yang sudah dideklarasikan tadi dijelaskan cara kerjanya. Fungsi createList digunakan untuk membuat list kosong dengan mengatur pointer first bernilai Nil. Fungsi alokasi bertugas membuat node baru dan mengisinya dengan angka yang dimasukkan pengguna, sedangkan dealokasi digunakan untuk menghapus node agar memori tidak terbuang sia-sia. Ada beberapa cara untuk menambahkan data ke dalam list: insertFirst untuk menambah di depan, insertLast untuk menambah di belakang, dan insertAfter untuk menambah setelah node tertentu. Untuk menghapus node, digunakan fungsi delAfter yang akan menghapus node setelah posisi tertentu. Kemudian, printList menampilkan semua isi list, sedangkan nbList menghitung berapa banyak node yang ada. Fungsi isEmpty digunakan untuk memeriksa apakah list kosong atau tidak.

Selain itu, terdapat tiga fungsi update, yaitu updateFirst, updateAfter, dan updateLast. Ketiganya digunakan untuk mengubah isi data angka pada node pertama, node terakhir, atau node setelah node tertentu. Saat dijalankan, program akan meminta pengguna untuk memasukkan angka baru, kemudian menggantikan nilai lama di node tersebut.

Pada file main.cpp, seluruh fungsi tadi dijalankan secara berurutan. Pertama, program membuat list kosong dengan createList, lalu membuat enam node baru (nodeA hingga nodeF) dengan angka berbeda menggunakan fungsi alokasi. Setelah itu, node-node tersebut dimasukkan ke dalam list dengan urutan tertentu menggunakan kombinasi insertFirst, insertLast, dan insertAfter. Namun, sebelum menampilkan hasilnya, satu node dihapus menggunakan delAfter, sehingga urutan angka yang tampil di list sudah tidak lengkap seperti sebelumnya.

Setelah itu, dilakukan proses update pada beberapa node — yaitu node pertama, node setelah node tertentu, dan node terakhir - agar nilai di dalam list berubah sesuai input pengguna. Akhirnya, program menampilkan hasil akhir list setelah dilakukan semua proses tersebut.

### 2. Soal unguided 2

Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst,node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tempilkan jumlah node yang terpisah menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList();


### 1. file ListAngka.h

```C++

#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct list {
    address first;
};

void createList(list &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(const list &L);
void insertFirst(list &L, address nodeBaru);
void insertAfter(list &L, address nodeBaru, address nodePrev);
void insertLast(list &L, address nodeBaru);
int nbList(const list &L);
void delAfter(list &L, address &nodeHapus, address nodePrev);
bool isEmpty(list L);

void updateFirst(list L);
void updateAfter(list L, address nodePrev);
void updateLast(list L);

void searchByData(list L, int data);
void searchByAddress(list L, address node);
void searchByRange(list L, int nilaiMin);

#endif


```

### 2. file singlylist.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

void createList(list &L) {
    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    if (nodeBaru != Nil) {
        nodeBaru->angka = x;
        nodeBaru->next = Nil;
    }
    return nodeBaru;
}

void dealokasi(address &node) {
    delete node;
    node = Nil;
}

void printList(const list &L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address p = L.first;
        while (p != Nil) {
            cout << p->angka << " - ";
            p = p->next;
        }
        cout << endl;
    }
}

void insertFirst(list &L, address nodeBaru) {
    if (nodeBaru != Nil) {
       nodeBaru->next = L.first;
       L.first = nodeBaru;
    }
}

void insertAfter(list &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil && nodeBaru != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else if (nodePrev == Nil) {
        cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
    }
}

void insertLast(list &L, address nodeBaru) {
    if (nodeBaru == Nil) return;

    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address p = L.first;
        while (p->next != Nil) {
            p = p->next;
        }
        p->next = nodeBaru;
    }
}

int nbList(const list &L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(list &L, address &nodeHapus, address nodePrev) {
    if (L.first == Nil) {
        nodeHapus = Nil;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
    } else {
        nodeHapus = Nil;
    }
}

bool isEmpty(list L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void updateFirst(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void  updateLast(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Angka : ";
        cin >> nodeBantu->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(list L, address nodePrev) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
            cout << "Angka : ";
            cin >> nodeBantu->angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void searchByData(list L, int data) {
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->angka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Angka : " << nodeBantu->angka << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void searchByAddress(list L, address node) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void searchByRange(list L, int nilaiMin) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu->angka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi 
                     << ", nilai : " << nodeBantu->angka << endl;
                cout << "---------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dengan nilai >= " << nilaiMin << endl;
        }
    }
    cout << endl;
}


```


### 3. file main.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    list L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    address nodeHapus = Nil;

    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(L);
    cout << "jumlah node : " << nbList(L) << endl;
    cout << endl;


    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);
    

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(L);
    cout << endl;

   searchByData(L, 20);      
    searchByData(L, 55);      
   searchByAddress(L, (address) 0x2748f6f3630);  
   searchByAddress(L, nodeD);  
   delAfter(L, nodeHapus, nodeC);
    cout << "--- Data diatas nilai 40 ---" << endl;
    cout << "---------------------------------------------" << endl;
    searchByRange(L, 40);     
    return 0;
}


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan5_modul5/ss-ungguided2.png)


penjelasan unguided 2

Program ini merupakan lanjutan dari program sebelumnya tentang linked list angka, namun dengan fungsi yang lebih lengkap karena telah ditambahkan fitur pencarian data (searching) berdasarkan isi data, alamat node, dan nilai tertentu. Jika sebelumnya program hanya bisa membuat, menambah, menghapus, serta memperbarui isi node, kini program juga dapat mencari dan menampilkan posisi atau alamat node yang sesuai dengan kriteria tertentu. Struktur dasarnya masih sama, terdiri dari dua bagian penting yaitu node, yang berisi data angka dan penunjuk ke node berikutnya, serta list, yang berfungsi menyimpan alamat node pertama. Fungsi dasar seperti createList, alokasi, insertFirst, insertAfter, insertLast, dan printList tetap digunakan untuk membentuk dan menampilkan isi list, sedangkan fungsi updateFirst, updateAfter, dan updateLast digunakan untuk memperbarui nilai pada node tertentu.

Bagian baru dari program ini adalah tiga fungsi pencarian, yaitu searchByData, searchByAddress, dan searchByRange. Fungsi searchByData digunakan untuk mencari node berdasarkan isi angkanya dengan menelusuri seluruh list dari awal hingga akhir, lalu menampilkan posisi node ketika data yang dicari ditemukan. Jika data tidak ada, program akan menampilkan pesan bahwa data tersebut tidak ditemukan. Fungsi searchByAddress digunakan untuk mencari node berdasarkan alamat memorinya (pointer) dengan cara membandingkan setiap alamat node dengan alamat yang dicari, lalu menampilkan posisi dan alamat node jika cocok. Jika alamat tidak ditemukan, maka akan muncul pesan bahwa alamat tersebut tidak ada di dalam list. Sementara itu, fungsi searchByRange berfungsi untuk mencari dan menampilkan semua node yang nilainya lebih besar atau sama dengan angka tertentu, misalnya nilai di atas 40, dan hasilnya ditampilkan lengkap dengan posisi dan nilai masing-masing node.

Pada bagian main.cpp, langkah awalnya sama seperti program sebelumnya, yaitu membuat enam node (nodeA hingga nodeF) menggunakan fungsi alokasi, kemudian menyusunnya menjadi sebuah list dengan kombinasi fungsi insertFirst, insertAfter, dan insertLast. Setelah semua node terbentuk, dilakukan proses pembaruan nilai menggunakan updateFirst, updateAfter, updateLast, dan updateAfter kembali agar hasilnya sesuai dengan yang diharapkan. Setelah proses update selesai, list ditampilkan ke layar dengan urutan 50 - 20 - 13 - 25 - 29 - 45 -.

Selanjutnya, program melakukan beberapa pencarian. Saat mencari angka 20, program berhasil menemukan bahwa angka tersebut berada di posisi ke-2, dan menampilkan hasilnya di layar. Saat mencari angka 55, karena tidak ada di dalam list, program menampilkan pesan bahwa node dengan data tersebut tidak ditemukan. Ketika program mencari node dengan alamat tertentu (misalnya 0x8f6f3630), hasilnya menunjukkan bahwa alamat itu tidak cocok dengan node mana pun di dalam list. Namun, ketika mencari berdasarkan alamat nodeD, program berhasil menemukannya di posisi ke-4 dan menampilkan alamat node yang sesuai. Terakhir, saat fungsi searchByRange dijalankan dengan parameter 40, program menampilkan data-data yang memiliki nilai lebih besar atau sama dengan 40, yaitu 50 di posisi pertama dan 45 di posisi kelima. Dengan demikian, program ini tidak hanya mampu menyimpan dan memperbarui data dalam list, tetapi juga dapat melakukan pencarian secara fleksibel untuk membantu pengguna memahami cara kerja linked list yang dinamis.list sepenuhnya.

### 3. Soal unguided 3

Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst,node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tempilkan jumlah node yang terpisah menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList();


### 1. file ListAngka.h

```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct list {
    address first;
};

void createList(list &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(const list &L);
void insertFirst(list &L, address nodeBaru);
void insertAfter(list &L, address nodeBaru, address nodePrev);
void insertLast(list &L, address nodeBaru);
int nbList(const list &L);
void delAfter(list &L, address &nodeHapus, address nodePrev);
bool isEmpty(list L);

void updateFirst(list L);
void updateAfter(list L, address nodePrev);
void updateLast(list L);

void searchByData(list L, int data);
void searchByAddress(list L, address node);
void searchByRange(list L, int nilaiMin);

int penjumlahan(list L);
int pengurangan(list L);
int perkalian(list L);

#endif

```

### 2. file ListAngka.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

void createList(list &L) {
    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    if (nodeBaru != Nil) {
        nodeBaru->angka = x;
        nodeBaru->next = Nil;
    }
    return nodeBaru;
}

void dealokasi(address &node) {
    delete node;
    node = Nil;
}

void printList(const list &L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address p = L.first;
        while (p != Nil) {
            cout << p->angka << " - ";
            p = p->next;
        }
        cout << endl;
    }
}

void insertFirst(list &L, address nodeBaru) {
    if (nodeBaru != Nil) {
       nodeBaru->next = L.first;
       L.first = nodeBaru;
    }
}

void insertAfter(list &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil && nodeBaru != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else if (nodePrev == Nil) {
        cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
    }
}

void insertLast(list &L, address nodeBaru) {
    if (nodeBaru == Nil) return;

    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address p = L.first;
        while (p->next != Nil) {
            p = p->next;
        }
        p->next = nodeBaru;
    }
}

int nbList(const list &L) {
    int count = 0;
    address p = L.first;
    while (p != Nil) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(list &L, address &nodeHapus, address nodePrev) {
    if (L.first == Nil) {
        nodeHapus = Nil;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
    } else {
        nodeHapus = Nil;
    }
}

bool isEmpty(list L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void updateFirst(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void  updateLast(list L) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Angka : ";
        cin >> nodeBantu->angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(list L, address nodePrev) {
    if(isEmpty(L) == true) {
        cout << "List Kosong" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->angka << " : " << endl;
            cout << "Angka : ";
            cin >> nodeBantu->angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void searchByData(list L, int data) {
    if(isEmpty(L) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->angka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Angka : " << nodeBantu->angka << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void searchByAddress(list L, address node) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void searchByRange(list L, int nilaiMin) {
    if(isEmpty(L) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu->angka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi 
                     << ", nilai : " << nodeBantu->angka << endl;
                cout << "---------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dengan nilai >= " << nilaiMin << endl;
        }
    }
    cout << endl;
}

int penjumlahan(list L) {
    int total = 0;
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address p = L.first;
        while (p != Nil) {
            total += p->angka;
            p = p->next;
        }
    }
    return total;
}

int pengurangan(list L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return 0;
    }

    int totalKurang = L.first->angka;  
    address p = L.first;
    while (p != Nil) {
        totalKurang -= p->angka;  
        p = p->next;
    }
    return totalKurang;
}

int perkalian(list L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return 0;
    }

    int totalKali = 1;
    address p = L.first;
    while (p != Nil) {
        totalKali *= p->angka;
        p = p->next;
    }
    return totalKali;
}

```


### 3. file main.cpp

```C++
#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    list L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    address nodeHapus = Nil;

    createList(L);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    delAfter(L, nodeHapus, nodeC);
    printList(L);
    cout << "jumlah node : " << nbList(L) << endl;
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, nodeF);
    

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    
    printList(L);
    cout << endl;

   searchByData(L, 20);      
    searchByData(L, 55);      
   searchByAddress(L, (address) 0x2748f6f3630);  
   searchByAddress(L, nodeD);  
    cout << "--- Data diatas nilai 40 ---" << endl;
    cout << "---------------------------------------------" << endl;
    searchByRange(L, 40);     

    cout << endl;
    cout << "Total penjumlahan : " << penjumlahan(L) << endl;
    cout << "Total pengurangan : " << pengurangan(L) << endl;
    cout << "Total perkalian   : " << perkalian(L) << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/maruf168/103112400128_Ma-ruf-Sarifudin/blob/main/pertemuan5_modul5/ss-ungguided3.png)


penjelasan unguided 3

Program ini merupakan lanjutan dari versi sebelumnya yang menggunakan linked list angka, tetapi kali ini kemampuannya lebih lengkap karena sudah ditambahkan fitur operasi aritmetika terhadap seluruh data di dalam list, yaitu penjumlahan, pengurangan, dan perkalian. Jika pada versi sebelumnya program hanya bisa membuat, menambah, menghapus, mengubah, dan mencari data dalam list, maka versi ini sudah bisa menghitung total dari semua nilai secara otomatis, sehingga hasil akhirnya lebih informatif dan fungsional.

Struktur utama program masih sama seperti sebelumnya. Terdapat dua bagian penting, yaitu node yang berisi satu nilai angka dan penunjuk next untuk menghubungkan ke node berikutnya, serta list yang menyimpan alamat node pertama. Fungsi dasar seperti createList, alokasi, insertFirst, insertAfter, insertLast, dan printList tetap digunakan untuk membuat dan menampilkan isi list. Sementara fungsi updateFirst, updateAfter, dan updateLast masih berfungsi untuk memperbarui nilai pada node tertentu agar sesuai dengan kebutuhan.

Perbedaan paling besar ada pada bagian akhir program, yaitu penambahan tiga fungsi baru: penjumlahan(), pengurangan(), dan perkalian(). Fungsi penjumlahan() menelusuri semua node dari awal hingga akhir, lalu menjumlahkan nilai tiap node ke dalam variabel total dengan nilai awal 0. Fungsi pengurangan() bekerja dengan cara mengambil nilai dari node pertama sebagai nilai awal, lalu menguranginya secara berurutan dengan nilai dari node-node berikutnya. Sedangkan fungsi perkalian() menggunakan nilai awal 1, kemudian mengalikan seluruh angka dalam list untuk mendapatkan hasil kali keseluruhan.

Di dalam file main.cpp, proses pembentukan list dilakukan seperti sebelumnya. Program membuat enam node (nodeA sampai nodeF) berisi angka 8, 13, 18, 25, 33, dan 40, lalu disusun menggunakan kombinasi fungsi insertFirst, insertAfter, dan insertLast untuk membentuk satu list utuh. Setelah itu, dilakukan proses pembaruan data melalui fungsi update hingga menghasilkan urutan list 50 - 20 - 25 - 29 - 45.

Setelah update selesai, program melakukan beberapa proses pencarian. Saat mencari angka 20, program menampilkan bahwa data tersebut ditemukan di posisi ke-2. Namun ketika mencari angka 55, muncul pesan bahwa data tidak ditemukan. Pencarian berdasarkan alamat memori juga dilakukan: jika alamat yang dicari tidak cocok dengan node mana pun, maka program menampilkan pesan bahwa alamat tersebut tidak ditemukan dalam list. Namun ketika mencari alamat nodeD, program berhasil menemukannya di posisi ke-3 dan menampilkan alamat memori node tersebut. Selain itu, fungsi searchByRange(L, 40) digunakan untuk menampilkan semua angka yang lebih besar atau sama dengan 40. Hasilnya menampilkan dua angka, yaitu 50 di posisi pertama dan 45 di posisi kelima.

Pada bagian akhir, program menampilkan hasil dari tiga operasi aritmetika. Total penjumlahan bernilai 169 karena hasil dari 50 + 20 + 25 + 29 + 45 = 169. Total pengurangan menghasilkan -119 karena dihitung mulai dari angka pertama (50) lalu dikurangi dengan seluruh angka dalam list (50 - 50 - 20 - 25 - 29 - 45 = -119). Sedangkan total perkalian menghasilkan 32625000 yang merupakan hasil dari mengalikan seluruh isi list.

Secara keseluruhan, program ini menunjukkan pengembangan dari versi sebelumnya dengan menambahkan fitur-fitur yang lebih kompleks dan berguna. Sekarang, linked list tidak hanya bisa menyimpan dan memanipulasi data, tetapi juga dapat digunakan untuk melakukan operasi matematis secara langsung terhadap seluruh elemen di dalamnya, menjadikannya contoh nyata bagaimana struktur data dinamis bekerja secara efisien dan terorganisir. 

## Kesimpulan
Kesimpulannya, Singly Linked List (SLL) adalah struktur data dinamis yang terdiri dari node-node yang saling terhubung melalui pointer, memungkinkan proses penambahan, penghapusan, pembaruan, dan pencarian data dilakukan dengan fleksibel tanpa perlu menggeser elemen lain seperti pada array. Struktur ini efisien dalam pengelolaan memori karena setiap node dialokasikan secara dinamis, namun memiliki kelemahan dalam akses data acak yang membutuhkan penelusuran berurutan. Secara keseluruhan, penggunaan SLL sangat bermanfaat untuk memahami konsep dasar struktur data dinamis dan penerapan logika pointer dalam pemrograman.

## Referensi
[1]Wijoyo, A., Prasetiyo, A. R., Salsabila, A. A., Nife, K., Murni, M., & Nadapdap, P. B. (2024). Evaluasi efisiensi struktur data Linked List pada implementasi sistem antrian. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1244–1246. https://jurnalmahasiswa.com/index.php/jriin
<br>[2] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Jurnal Penelitian Nusantara, 1(6), 871-877.
<br>[3] Chrismono, A., & Ningsih, D. H. U. (2022). Single Linked List Method for Selection of SMA/SMK in Semarang Based on Nearest Neighbor Algorithm and Spatial Buffering Analysis. JEEE-U (Journal of Electrical and Electronic Engineering-UMSIDA), 6(1), 70-82.


