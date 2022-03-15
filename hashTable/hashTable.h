#include <stdio.h>
#include "../cppLists/cppLists.h"

class CHashTbl
{
private:
    CLists*         lists_  = NULL;
    int             size_   =    0;

public:
    explicit        CHashTbl (int size);
                    ~CHashTbl ();  

    int             Dump ();  
};
