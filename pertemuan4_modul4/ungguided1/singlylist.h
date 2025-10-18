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