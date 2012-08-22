//---------------------------------------------------------------------------
//#include <vcl.h>
//#pragma hdrstop

#include "Memory.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
template <class Stype> Memory <Stype>::Memory(long Num)
{
*Mem=new Stype [Num];
}
template <class Stype> Memory <Stype>::~Memory()
{
delete Mem;
}
//template <class Stype> Memory Stype& operator [](long Num)
//{
//return Mem[Num];
//}

