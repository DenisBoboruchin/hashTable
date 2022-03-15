#include "hashTable.h"

CHashTbl::CHashTbl (int size) :
    lists_ (new CLists[size]),
    size_ (size)
{}

CHashTbl::~CHashTbl ()
{
    //delete (lists_);
    size_ = DESTROYED;
}

int CHashTbl::Dump ()
{
    DotCtor ();

    for (int i = 0; i < size_; i++)
        lists_[i].ListDump (); 

    DotEnd ();

    return NOMISTAKE;
}
