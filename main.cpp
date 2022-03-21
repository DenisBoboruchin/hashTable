#include <stdio.h>
#include "hashTable/hashTable.h"

int main ()
{
    CHashTbl t1 (50);


    for (int i = 0; i < 200; i++)
        t1.insert (i);
    
    for (int i = 0; i < 200; i++)
        t1.insert (i);

    for (int i = 0; i < 15; i++)
        t1.del (i);

    t1.dump (); 

    return 0;
}
