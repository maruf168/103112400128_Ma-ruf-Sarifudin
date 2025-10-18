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