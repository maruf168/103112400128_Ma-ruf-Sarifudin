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