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
