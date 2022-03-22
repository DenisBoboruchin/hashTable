#include <stdio.h>

#include "FormatFile.h"
#include "SortText.h"

//#define NDEBUG

#define FORMTEXT
#define SORTEDTEXT

const char* nameIn   = "hamlet.txt";
const char* nameOut  = "FormatFile.txt";
const char* origName = "FormatFile.txt";
const char* resName  = "ResultFile.txt";

int main(void)
{
    #ifdef FORMTEXT
        FormFile(nameIn, nameOut);

    #endif

    #ifdef SORTEDTEXT
        SortText(origName, resName);

    #endif

    return 0;
}
