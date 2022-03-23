#include <stdio.h>

#include "hashTable/hashTable.h"
#include "onegin/SortText.h"
#include "onegin/FormatFile.h"

const char* text        = "text.txt";
const char* formText    = "formText.txt";

int main ()
{
    FormFile (text, formText);

    size_t sizeBuf = GetSizeBuf (formText);

    char* buffer = CreateBuf (&sizeBuf, formText);
    
    size_t numberLines = NumberLines (buffer, sizeBuf);

    struct pointStr* strings = CrtorStrs (numberLines, sizeBuf, buffer);

    CHashTbl t1 ((int) numberLines / 2);

    for (int i = 0; i < (int) numberLines; i++)
        t1.insert (strings[i].str);

    t1.countElem ("First");
    //for (int i = 0; i < 200; i++)
     //   t1.insert (i);
    
   // for (int i = 0; i < 200; i++)
     //   t1.insert (i);

    //for (int i = 0; i < 15; i++)
      //  t1.del (i);

    t1.dump (); 
    
    //free (buffer);
    //free (strings);

    return 0;
}

