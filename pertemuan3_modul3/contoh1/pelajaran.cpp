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
