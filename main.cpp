#include <stdio.h>
#include "hashTable/hashTable.h"

int main ()
{
    CHashTbl t1 (10);


    for (int i = 0; i < 20; i++)
        t1.insert (i);
    
    for (int i = 0; i < 20; i++)
        t1.insert (i);

    for (int i = 0; i < 10; i++)
        t1.del (i);

    t1.dump (); 

    return 0;
}
