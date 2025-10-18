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
