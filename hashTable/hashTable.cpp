#include "hashTable.h"

CHashTbl::CHashTbl (int size) :
    lists_ (new CLists[size]),
    size_ (size)
{}

CHashTbl::~CHashTbl ()
{
    delete[] lists_;
    size_ = DESTROYSZ;
}

int CHashTbl::dump ()
{
    DotCtor ();

    for (int i = 0; i < size_; i++)
        lists_[i].ListDump (); 

    DotEnd ();

    return NOMISTAKE;
}

int CHashTbl::insert (ElemType data)
{
    int index = Hash_ ((char*) &data, sizeof (data));

    int position = lists_[index].FoundElem (data);

    if (position != NOTFOUND)
        return NOMISTAKE;                           //done counter 

    lists_[index].ListInsertHead (data);

    return NOMISTAKE;
}

int CHashTbl::del (ElemType data)
{
    int index = Hash_ ((char*) &data, sizeof (data));
    
    int position = lists_[index].FoundElem (data);
    
    if (position == NOTFOUND)
    {
        printf ("Element ");
        printf (ELEM_FMT, data);
        printf (" not found\n");

        return NOMISTAKE;
    }
    
    lists_[index].ListDelete (position); 

    return NOMISTAKE;
}

int CHashTbl::Hash_ (char* key, unsigned int len)
{
  const unsigned int m      = 0x5bd1e995;
  const unsigned int seed   = 0;
  const int r = 24;

  unsigned int h = seed ^ len;

  const unsigned char* data = (const unsigned char*) key;
  unsigned int k = 0;

  while (len >= 4)
  {
      k  = data[0];
      k |= data[1] << 8;
      k |= data[2] << 16;
      k |= data[3] << 24;

      k *= m;
      k ^= k >> r;
      k *= m;

      h *= m;
      h ^= k;

      data += 4;
      len  -= 4;
  }

  switch (len)
  {
    case 3:
      h ^= data[2] << 16;
      break;

    case 2:
      h ^= data[1] << 8;
      break;

    case 1:
      h ^= data[0];
      h *= m;
      break;

    case 0:
      break;

    default:
      printf ("HASH ERROR!!!\n");
      break;
  };

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h % size_;
}
