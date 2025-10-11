

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